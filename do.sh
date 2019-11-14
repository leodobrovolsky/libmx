if [[ $1 == "compile" ]]; then
	make uninstall
	make
fi
if [[ $1 == "test" ]]; then
	rm test
	touch test
fi
if [[ $1 == "cmptest" ]]; then
	make uninstall
	make
	rm test
	touch test
fi
clang main.c libmx.a
./a.out