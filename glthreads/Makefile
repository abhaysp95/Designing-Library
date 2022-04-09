TARGET: my_gldll

my_gldll: main.o libgldll.a
	gcc -L . main.o -lgldll -o $@

libgldll.a: glthread.o
	ar rs $@ $^

main.o: main.c
	gcc -c -I . $^ -o $@

glthread.o: glthread.c
	gcc -c -I . $^ -o $@

clean:
	rm *.a
	rm *.o
	rm my_gldll
