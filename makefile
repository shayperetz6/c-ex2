FLAGS = -Wall -g
CC = gcc
AR = ar 
all: libmyBank.a main
main: main.o libmyBank.a
	$(CC) $(FLAGS) -o main main.o libmyBank.a
libmyBank.a: myBank.o
	$(AR) -rcs  libmyBank.a myBank.o
main.o: main.c myBank.h
	$(CC) $(FLAGS) -c main.c

myBank.o: myBank.c myBank.h
	$(CC) $(FLAGS) -c myBank.c	

.PHONY: clean all 

clean:
	rm -f *.o *.a main