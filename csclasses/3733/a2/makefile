compileAll : assign2 test

assign2 : assign2.o pslibrary.o
	gcc -Wall assign2.o pslibrary.o -o assign2 

test: runall.o pslibrary.o
	gcc -Wall runall.c pslibrary.c -o test

runall.o: runall.c pslibrary.h
	gcc -Wall -c runall.c

assign2.o : assign2.c pslibrary.h
	gcc -Wall -c assign2.c

pslibrary.o : pslibrary.c
	gcc -Wall -c pslibrary.c

clear : 
	rm *.o assign2 test
