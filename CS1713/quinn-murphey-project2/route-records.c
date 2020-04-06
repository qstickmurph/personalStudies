#include "route-records.h"

RouteRecord *createRecords( FILE *fileIn){
	
	
	
}

int fillRecords( RouteRecord *r, FILE *fileIn);

int findAirlineRoute( RouteRecord *r, int length, const char *origin, const char *destination, const char *airline);

void searchRecords( RouteRecord *r, int length, const char *key1, const char *key2, SearchType st);

void printRecords( RouteRecord *r, int length);

void printMenu();

