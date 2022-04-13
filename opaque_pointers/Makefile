TARGET: my_opaque_ptr

my_opaque_ptr: application.o liblld.a
	gcc -L . -llld $^ -o $@

liblld.a: linkedlist.o
	ar rs $@ $^

application.o: application.c
	gcc -c -I . $^ -o $@

linkedlist.o: linkedlist.c
	gcc -c -I . $^ -o $@

clean:
	rm *.a
	rm *.o
	rm my_opaque_ptr
