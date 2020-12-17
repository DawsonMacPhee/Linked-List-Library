CFLAGS = -std=c99 -Wall -pedantic
CC = gcc

all: list.o test1 test2 test3

list.o: list.c
	$(CC) $(CFLAGS) -c list.c -o list.o

test1.o: test1.c
	$(CC) $(CFLAGS) -c test1.c -o test1.o

test2.o: test2.c
	$(CC) $(CFLAGS) -c test2.c -o test2.o -DLIST

test3.o: test3.c
	$(CC) $(CFLAGS) -c test3.c -o test3.o

test1: list.o test1.o
	$(CC) $(CFLAGS) list.o test1.o -o test1

test2: list.o test2.o
	$(CC) $(CFLAGS) list.o test2.o -o test2

test3: list.o test3.o
	$(CC) $(CFLAGS) list.o test3.o -o test3

clean: 
	rm list.o test1.o test2.o test3.o test1 test2 test3