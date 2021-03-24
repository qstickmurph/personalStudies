runMe : Lab1main.o QuinnMurpheyLab1methods.o
	gcc -Wall Lab1main.o QuinnMurpheyLab1methods.o -o runMe -lm

Lab1main.o: Lab1main.c
	gcc -Wall -lm -c Lab1main.c

QuinnMurpheyLab1methods.o: QuinnMurpheyLab1methods.c QuinnMurpheyLab1methods.h
	gcc -Wall -lm -c QuinnMurpheyLab1methods.c

clear: 
	rm *.o runMe
