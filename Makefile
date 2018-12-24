CC=gcc

all: main.o stack.o
	CC -o rpn_programm main.o stack.o

main.o: main.c stack.h
	CC -c main.c

stack.o: stack.c
	CC -c stack.c

clean:
	rm -rf rpn_programm main.o stack.o
