runme : project2-main.o route-records.o
	gcc project2-main.o route-records.o -o runme

project2-main.o : project2-main.c route-records.h
	gcc -Wall -c project2-main.c

route-records.o : route-records.c route-records.h
	gcc -Wall -c route-records.c

clean :
	rm *.o runme
