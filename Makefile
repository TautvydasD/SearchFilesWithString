CC=gcc
CFLAGS=-Wall -Werror -pedantic -g -o
LD_LIBRARY_PATH=${PWD}/lib
PROJECT=main.o main.c
EX=test.o test.c 

all: clean; $(CC) $(CFLAGS) $(EX); $(CC) $(CFLAGS) $(PROJECT)

run: clean; $(CC) $(CFLAGS) main.o main.c lib/dynlib.c ; ./main.o -f . -t printf

clean: ; rm -f test ex1 *.out *.o

# dynamic: ; $(CC) -Wall -pedantic -shared -fpic -o ./lib/dynlib.so ./lib/dynlib.c

rundyn: clean; dynamic; $(CC) -g -Wall -Werror -pedantic -o main.o main.c -L./lib/dynlib -l./lib/dynlib

dynamic: ; $(CC) -fPIC -c ./lib/*.c & mv dynlib.o ./lib ; $(CC) -shared -Wl,-soname,./lib/dynlib.so -o ./lib/dynlib.so ./lib/*.o