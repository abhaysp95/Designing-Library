TARGET: all

all: my_array

my_array: array.o
	gcc -L . -o $@ $^

array.o: array.c
	gcc -I . -c -o $@ $^

clean:
	rm *.o
	rm my_array
