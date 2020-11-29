runMe : main.o BST.o
	gcc main.o BST.o -o runMe

main.o : main.c BST.h
	gcc -Wall -c main.c

BST.o : BST.c BST.h
	gcc -Wall -c BST.c

clear :
	rm *.o runMe
