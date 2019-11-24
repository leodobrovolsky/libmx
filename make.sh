rm -rf tmp1.txt
rm -rf tmp2.txt
rm -rf tmp3.txt
rm -rf Makefile

if [[ $2 == "lib" ]]
then
	PARAM=".a"
else
	PARAM=""
fi

#libs
touch tmp2.txt
for i in $(ls -d */)
do
	if [[ $i != "src/" && $i != "inc/" && $i != "test/" && $i != "tests/" ]]
	then
		echo $i | tr '/' ' ' | sed 's/ //' >> tmp2.txt
	fi
done

#include
touch tmp3.txt
FILE="inc/${1}.h"
if [[ -e $FILE ]]
then
	IND="0"
	while read LINE
	do  
		temp=$(echo $LINE | grep "typedef") 
		if [[ $temp != "" ]]
		then
			IND="1"
		fi

		temp2=$(echo $LINE | grep "}") 
		if [[ $temp2 != "" ]]
		then
			if [[ $IND == "1" ]]
			then
				echo "$LINE\n"  >> tmp3.txt
				IND="0"
	        else
				IND="0"
			fi
		fi	

		if [[ $IND == "1" ]]
		then
			echo $LINE  >> tmp3.txt
		fi
	done < $FILE
fi

rm -rf inc
mkdir -p inc
echo "#ifndef ${1}_h\n#define ${1}_h\n\n#include <stdlib.h>\n#include <unistd.h>\n#include <stdbool.h>\n#include <fcntl.h>\n\n" >> "inc/${1}.h"
cd src
INC=$(ls -1 *.c)
cd ..
cat tmp3.txt >> "inc/${1}.h"
echo $INC | tr ' ' '\n' | sed 's/.$//' | sed 's/.$//' >> tmp1.txt
for i in $(cat tmp1.txt)
do
    cat "src/${i}.c" | grep "${i}" | head -1| tr '{' ';' | sed 's/ ;/;/'  >> "inc/${1}.h"
done

LIBS=""
for i in $(cat tmp2.txt)
do
	LIBS="$LIBS $i.a"
	FILE="$i/inc/$i.h"
	if [[ -e $FILE ]]
	then
		echo "\n\n//$i" >> "inc/${1}.h"
		while read LINE
			do  
			temp=$(echo $LINE | grep "#") 
			if [[ $temp == "" ]]
			then
				echo $LINE >> "inc/${1}.h"
		    fi
		done < $FILE
	fi
done

echo "#endif\n" >> "inc/${1}.h"

#Makefile
echo "NAME = ${1}${PARAM}\n\nCFLAG = -std=c11 -Wall -Wextra -Werror -Wpedantic\n\nLIBS = $LIBS\n\nINC = inc/${1}.h\n\nINCS = ${1}.h\n" >> Makefile

SRCS=""
SRC=""
OBJS=""
OBJ=""

for i in $(cat tmp1.txt)
do
	SRCS="$SRCS $i.c"
	SRC="$SRC src/$i.c"
   	if [[ $2 == "lib" ]]
   	then
		OBJS="$OBJS $i.o"
		OBJ="$OBJ obj/$i.o"
	fi
done
echo "SRC = ${SRC}\n" >> Makefile
echo "SRCS = ${SRCS}\n" >> Makefile
if [[ $2 == "lib" ]] 
then
	echo "OBJ_DIR = obj\n" >> Makefile
	echo "OBJ = ${OBJ}\n" >> Makefile
	echo "OBJS = ${OBJS}\n" >> Makefile
fi

#all
echo "\nall: install clean" >> Makefile

#install
echo "install:" >> Makefile
if [[ $2 == "lib" ]]
then
	echo "\t@mkdir -p \$(OBJ_DIR)\n\t@cp \$(SRC) .\n\t@cp \$(INC) .\n\t@clang \$(CFLAG) -c \$(SRCS) -I \$(INCS)\n\t@cp \$(OBJS) \$(OBJ_DIR)\n\t@rm -rf \$(OBJS)\n\t@ar -cq \$(NAME) \$(OBJ)" >> Makefile
else
	for i in $(cat tmp2.txt)
	do
		echo "\t@make -f $i/Makefile install\n\t@cp $i/$i.a ." >> Makefile
	done
	echo "\t@cp \$(SRC) .\n\t@cp \$(INC) .\n\t@clang \$(CFLAG) -o \$(NAME) \$(SRCS) -I \$(INCS) \$(LIBS)" >> Makefile
fi

#uninstall
echo "uninstall: clean\n\t@rm -rf \$(NAME)" >> Makefile
for i in $(cat tmp2.txt)
	do
		echo "\t@make -f $i/Makefile uninstall" >> Makefile
	done
#clean
if [[ $2 == "lib" ]]
then
	echo "clean:\n\t@rm -rf \$(SRCS)\n\t@rm -rf \$(INCS)\n\t@rm -rf \$(OBJ_DIR)" >> Makefile
else
	echo "clean:\n\t@rm -rf \$(SRCS)\n\t@rm -rf \$(INCS)\n\t@rm -rf \$(LIBS)" >> Makefile
fi
for i in $(cat tmp2.txt)
	do
		echo "\t@make -f $i/Makefile clean" >> Makefile
	done
#reinstall
echo "reinstall:" >> Makefile
for i in $(cat tmp2.txt)
	do
		echo "\t@make -f $i/Makefile reinstall" >> Makefile
	done
if [[ $2 == "lib" ]]
then
	echo "\t@rm -rf \$(SRCS)\n\t@rm -rf \$(INCS)\n\t@rm -rf \$(OBJ_DIR)\n\t@rm -rf \$(NAME)\n\t@mkdir -p \$(OBJ_DIR)\n\t@cp \$(SRC) .\n\t@cp \$(INC) .\n\t@clang \$(CFLAG) -c \$(SRCS) -I \$(INCS)\n\t@cp \$(OBJS) \$(OBJ_DIR)\n\t@rm -rf \$(OBJS)\n\t@ar -cq \$(NAME) \$(OBJ)\n\t@rm -rf \$(SRCS)\n\t@rm -rf \$(INCS)\n\t@rm -rf \$(OBJ_DIR)" >> Makefile
else
	echo "\t@rm -rf \$(SRCS)\n\t@rm -rf \$(INCS)\n\t@rm -rf \$(LIBS)\n\t@rm -rf \$(NAME)\n\t@cp \$(SRC) .\n\t@cp \$(INC) .\n\t@clang \$(CFLAG) -o \$(NAME) \$(SRCS) -I \$(INCS) \$(LIBS)\n\t@rm -rf \$(SRCS)\n\t@rm -rf \$(INCS)\n\t@rm -rf \$(LIBS)" >> Makefile
fi

rm -rf tmp1.txt
rm -rf tmp2.txt
rm -rf tmp3.txt