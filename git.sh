if [[ $#  > 0 ]]
then
	for i in $@
        do
		git add $i
	done
else 
	git add .
fi
git status
read -p "Press y to confirm" -n 1 -r choice
if [[ $choise == "y" ]]
then 
	ls
fi
