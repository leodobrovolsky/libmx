if [[ $1 == "compile" ]]; then
	make uninstall
	make
fi
clang main.c libmx.a
./a.out