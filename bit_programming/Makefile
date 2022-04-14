TARGET: all

all: my_bit_operations my_bit_assignment

my_bit_assignment: assignment.o
	gcc -L . $^ -o $@

my_bit_operations: application.o
	gcc -L . $^ -o $@

assignment.o: assignment.c
	gcc -I . -c $^ -o $@

application.o: application.c
	gcc -I . -c $^ -o $@

help:
	@echo "... all"
	@echo "... my_bit_assignment"
	@echo "... my_bit_operations"
	@echo "... assignment.o"
	@echo "... application.o"
	@echo "... clean"

clean:
	rm *.o
	# rm my_bit_operations
	rm my_bit_assignment
