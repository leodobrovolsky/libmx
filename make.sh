rm -rf inc
mkdir -p inc
rm -rf tmp1.txt
rm -rf Makefile
cd src

#include
rm -rf "$../inc/{1}.h"
echo "#ifndef MYHEADERS_H\n#define MYHEADERS_H\n\n#include <stdlib.h>\n#include <unistd.h>\n#include <stdbool.h>\n#include <fcntl.h>\n#include <stdio.h>\n\n" >> "../inc/${1}.h"
INC=$(ls -1 *.c)
echo $INC | tr ' ' '\n' | sed 's/.$//' | sed 's/.$//' >> ../tmp1.txt
for i in $(cat ../tmp1.txt)
do
    cat "${i}.c" | grep "${i}" | head -1| tr '{' ';' | sed 's/ ;/;/'  >> "../inc/${1}.h"
done
echo "#endif\n" >> "../inc/${1}.h"

#Makefile
SRCS=$(ls *.c | tr '\n' ' ')
cd ..
echo "NAME = ${1}\n\nCFLAG = -std=c11 -Wall -Wextra -Werror -Wpedantic\n\nOBJ_DIR = obj\n\nINC = inc/${1}.h\n\nINCS = ${1}.h\n\nSRCS = ${SRCS}" >> Makefile


SRC=""
for i in $(cat tmp1.txt)
do
	SRC="$SRC src/$i.c"
done
echo "\nSRC = ${SRC}\n" >> Makefile


OBJS=""
for i in $(cat tmp1.txt)
do
	OBJS="$OBJS $i.o"
done
echo "OBJS = ${OBJS}\n" >> Makefile

OBJ=""
for i in $(cat tmp1.txt)
do
	OBJ="$OBJ obj/$i.o"
done
echo "OBJ = ${OBJ}\n" >> Makefile

rm -rf tmp1.txt

echo "\nall: install clean\ninstall:\n\nuninstall: clean\n\t@rm -rf ${1}\nclean:\n\nreinstall: uninstall clean all" >> Makefile