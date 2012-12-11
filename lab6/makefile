%.o: %.asm
	nasm -g -O1 -f elf -o $@ $<

%.o: %.c
	gcc -m32 -g -c -o $@ $<

all: bcmp 

bcmp: bcmp.o bcmpa.o
	gcc -m32 -o $@ $^

bcmp.o:bcmp.c
bcmpa.o:bcmpa.asm

clean:
	rm *.o

