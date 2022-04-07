TARGET: all

all: my_dll

my_dll: application.o libdll.a
	gcc application.o -o my_dll -L . -ldll

libdll.a: dll.o dll_util.o
	ar rs libdll.a dll.o dll_util.o

dll.o: dll.c
	gcc -c -I . dll.c -o dll.o

dll_util.o: dll_util.c
	gcc -c -I . dll_util.c -o dll_util.o

application.o: application.c
	gcc -c -I . application.c -o application.o

clean:
	rm *.o
	rm libdll.a
	rm my_dll
