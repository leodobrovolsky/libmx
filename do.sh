if [[ $1 == "compile" ]]; then
	make uninstall
	make
fi
if [[ $1 == "test" ]]; then
	rm test
	touch test
fi
clang main.c libmx.a
./a.out