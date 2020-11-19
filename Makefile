hdecode: main.o tree.o
	gcc -std=c99 -pedantic -Wall -g -o hdecode main.o tree.o

main.o: main.c
	gcc -std=c99 -pedantic -Wall -c main.c

tree.o: tree.c
	gcc -std=c99 -pedantic -Wall -c tree.c

clean:
	rm -f hdecode main.o tree.o

