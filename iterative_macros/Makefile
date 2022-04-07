TARGET: all

all: my_dll my_tree

my_tree: tree.o
	gcc -o $@ -L . $^

tree.o: tree.c
	gcc -I . -c $^ -o $@

my_dll: application.o libdll.a
	gcc -o $@ -L . -ldll $^

libdll.a: dll.o dll_util.o
	ar rs $@ $^

dll.o: dll.c
	gcc -I . -c $^ -o $@

dll_util.o: dll_util.c
	gcc -I . -c $^ -o $@

application.o: application.c
	gcc -I . -c $^ -o $@

clean:
	rm *.o
	rm *.a
	rm my_dll
