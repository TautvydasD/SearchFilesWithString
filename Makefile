CC=gcc
CFLAGS=-Wall -Werror -pedantic -g -o
LD_LIBRARY=$(shell pwd)
PROJECT=main.o main.c

all: libdyn.so prog

prog: main.c
	$(CC) -o prog main.c -L$(LD_LIBRARY) -ldyn -Wl,-rpath=$(LD_LIBRARY)

libdyn.so: ./lib/dynlib.c ./lib/dynlib.h
	$(CC) -Wall -shared -fPIC -o libdyn.so ./lib/dynlib.c

clean:
	rm -f libdyn.so prog