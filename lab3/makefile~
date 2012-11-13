all: bfix bcmp

bfix: bfix.o diff.o

bfix.o: bfix.c diff.h
diff.o: diff.c diff.h

bcmp: bcmp.o
	gcc -o bcmp bcmp.o

clean:
	rm *.o

bcmp.o: bcmp.c
	gcc -c bcmp.c
