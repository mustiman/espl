all: canalyze 

canalyze: canalyze.o fgetname.o
	gcc -o canalyze canalyze.o fgetname.o


canalyze.o: canalyze.c fgetname.h 
	gcc -Wall -c -o canalyze.o canalyze.c


namelist.o: namelist.c namelist.h

fgetname.o: fgetname.c fgetname.h

clean:
	rm -f testnl testfgn canalyze *.o
