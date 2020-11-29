runMe : main.o cards.o
	gcc main.o cards.o -o runMe

main.o : main.c cards.h
	gcc -Wall -c main.c

cards.o : cards.c cards.h
	gcc -Wall -c cards.c

clear :
	rm *.o runMe
