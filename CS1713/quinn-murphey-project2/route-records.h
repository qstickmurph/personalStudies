#ifndef ROUTE-RECORDS.H
#define ROUTE-RECORDS.H


typedef struct RouteRecords RouteRecord{
	
	char origin[4];
	char destination[4];
	char airline[3];
	int passengerCount[6];

} RouteRecord;

typedef enum SearchType { ROUTE, ORIGIN, DESTINATION, AIRLINE } SearchType;

RouteRecord *createRecords( FILE *fileIn);

int fillRecords( RouteRecord *r, FILE *fileIn);

int findAirlineRoute( RouteRecord *r, int length, const char *origin, const char *destination, const char *airline);

void searchRecords( RouteRecord *r, int length, const char *key1, const char *key2, SearchType st);

void printRecords( RouteRecord *r, int length);

void printMenu();


#endif
