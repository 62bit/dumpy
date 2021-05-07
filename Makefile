CFLAGS=-O2 -Wall -Wextra -pedantic -std=c99

main:main.c
	gcc $(CFLAGS) -o dumpy main.c

clean:
	rm -f *.o
	rm -f *.out
	rm -f *.core
