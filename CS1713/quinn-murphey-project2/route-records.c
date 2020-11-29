#include "route-records.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

RouteRecord *createRecords( FILE *fileIn ){
	
	char buffer[500];
	
	fgets(buffer, 10, fileIn); //skip first line
	int entryCount = 0;

	while(fgets(buffer, 500, fileIn) != 0){ //count lines after first
		entryCount ++;
	}

	RouteRecord *recordArray = (malloc(sizeof(RouteRecord) * entryCount)); //dynamically initialize RouteRecord array

	for(int i = 0; i < entryCount; ++i){ //set all inital passenger counts to 0
		recordArray[i].passengerCount[0] = 0;
		recordArray[i].passengerCount[1] = 0;
		recordArray[i].passengerCount[2] = 0;
		recordArray[i].passengerCount[3] = 0;
		recordArray[i].passengerCount[4] = 0;
		recordArray[i].passengerCount[5] = 0;
	}

	rewind(fileIn); //set seek to first line
	return recordArray;
	
}

int fillRecords( RouteRecord *r, FILE *fileIn){
	
	char buffer[500];

	fgets(buffer, 500, fileIn); //skip first line

	int recordNumber = 0;
	while(fgets(buffer, 500, fileIn) != 0){ //reads each line after the first

		char origin[4], destination[4], airline[3];
		int month, passengers;

		if (5 != sscanf(buffer, "%d,%3s,%3s,%2s,Passengers,%d", &month, origin, destination, airline, &passengers)){ //skips line if incorrectly formatted
			continue;
		}
		
		int prevRecord = findAirlineRoute( r, recordNumber, origin, destination, airline); //checks and sees if this origin/destination/airline combo has been entered before

		if (prevRecord != -1){
			strcpy(r[prevRecord].origin, origin);
			strcpy(r[prevRecord].destination, destination);
			strcpy(r[prevRecord].airline, airline);
			r[prevRecord].passengerCount[month - 1] = passengers;

		}else{ //makes a new entry if it hasnt been used
			strcpy(r[recordNumber].origin, origin);
			strcpy(r[recordNumber].destination, destination);
			strcpy(r[recordNumber].airline, airline);
			r[recordNumber].passengerCount[month - 1] = passengers;

			recordNumber++;
		}
	}

	return recordNumber;
	
}

int findAirlineRoute( RouteRecord *r, int length, const char *origin, const char *destination, const char *airline){
	
	for(int i = 0; i < length; ++i){
		
		if(strcmp(origin, r[i].origin) == 0 && strcmp(destination, r[i].destination) == 0 && strcmp(airline, r[i].airline) == 0){
			return i;
		}
		
	}
	
	return -1;

}

void searchRecords( RouteRecord *r, int length, const char *key1, const char *key2, SearchType st){
	int numMatches = 0;
	RouteRecord *matches = malloc(sizeof(RouteRecord) * length);

	for(int i = 0; i < length; ++i){ //searches r to create list of matches and prints them
		switch(st){
			case ORIGIN:
				if(strcmp(r[i].origin, key1) == 0){
					
					printf("%3s (%3s -> %3s), ", r[i].airline, r[i].origin, r[i].destination);
					matches[numMatches] = r[i];
					numMatches++;

				}
				break;
			case DESTINATION:
				if(strcmp(r[i].destination, key1) == 0){
					
					printf("%3s (%3s -> %3s), ", r[i].airline, r[i].origin, r[i].destination);
					matches[numMatches] = r[i];
					numMatches++;

				}
				break;
			case AIRLINE:
				if(strcmp(r[i].airline, key1) == 0){
					
					printf("%3s (%3s -> %3s), ", r[i].airline, r[i].origin, r[i].destination);
					matches[numMatches] = r[i];
					numMatches++;

				}
				break;
			case ROUTE:
				if(strcmp(r[i].origin, key1) == 0 && strcmp(r[i].destination, key2) == 0){
					
					printf("%3s (%3s -> %3s), ", r[i].airline, r[i].origin, r[i].destination);
					matches[numMatches] = r[i];
					numMatches++;

				}
				break;
		}
	}

	printf("\nNumber of matches: %d\n\nStatistics:\n", numMatches);


	int passengerSum[6] = {0, 0, 0, 0, 0, 0};
	for(int i = 0; i < numMatches; ++i){
		for(int j = 0; j < 6; ++j){
			passengerSum[j] += matches[i].passengerCount[j];
		}	
	}
	for(int i = 0; i < 6; ++i){
		printf("Month %d: %d\n", i+1, passengerSum[i]);
	}

	printf("\nAverage Passengers per Month: %d\n", (passengerSum[0] + passengerSum[1] + passengerSum[2] + passengerSum[3] + passengerSum[4] + passengerSum[5])/6 );

	free(matches);
		
}

void printRecords( RouteRecord *r, int length){
	for(int i = 0; i < length; ++i){
		printf("%3s (%3s -> %3s), ", r[i].airline, r[i].origin, r[i].destination);
	}
}

void printMenu(){
	
	printf( "\n\n######### Airline Route Records Database MENU #########\n" );
	printf( "1. Search by Route\n" );
	printf( "2. Search by Origin Airport\n" );
	printf( "3. Search by Destination Airport\n" );
	printf( "4. Search by Airline\n" );
	printf( "5. Quit\n" );
	printf( "Enter your selection: " );
	
}
