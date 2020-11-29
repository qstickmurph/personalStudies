runMe : main.o student.o
	gcc main.o student.o -o runMe

main.o : main.c student.h
	gcc -Wall -c main.c

student.o : student.c student.h
	gcc -Wall -c student.c

clear: 
	rm *.o runme
