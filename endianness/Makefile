TARGET: main

main: main.c
	gcc $^ -o $@

main_debug: main.c
	gcc -ggdb $^ -o $@

clean:
	rm main main_debug
