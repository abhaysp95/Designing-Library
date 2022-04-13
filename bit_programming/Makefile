TARGET: my_bit_operations

my_bit_operations: application.o
	gcc -L . $^ -o $@

application.o: application.c
	gcc -I . -c $^ -o $@

clean:
	rm *.o
	rm my_bit_operations
