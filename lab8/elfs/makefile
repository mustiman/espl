# generic rule for compiling C files

CFLAGS=-g -O -Wall

%.o: %.c
	gcc -c $(CFLAGS) -o $@ $<

%: %.o
	gcc $(CFLAGS) -o $@ $<

all: a b

a: secret-elf-a secret-elf-c
b: secret-elf-b secret-elf-c

clean:
	rm -f *.o

