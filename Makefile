install:
	mv main /usr/bin/

main: main.o
	gcc main.o -o main

main.o: main.c
	gcc main.c -c

clean:
	rm main.o
