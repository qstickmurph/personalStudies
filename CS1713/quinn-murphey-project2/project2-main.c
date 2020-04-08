#include <stdio.h>
#include <stdlib.h>
#include "route-records.h"


int main( int argc, char *argv[] )
{
    int menuInput;
	char input1[100];
	char input2[100];
	FILE *fileIn;

    if(argc != 2){
		if( argc < 2){
			printf("ERROR: Missing file name");
			return -1;
		}
		else{
			printf("ERROR: Too many arguments");
			return -1;
		}
	}

    /* 2. Check command line arguments here. If a command line argument (for the file name) is missing, print out the following: ERROR: Missing file name and end the program */
    
	printf("Opening %s . . .\n", argv[1]);
	fileIn = fopen(argv[1], "r");

    /* 3. Attempt to open the file. Print out Opening <filename>... before you call fopen(). */
	
	if(fileIn == NULL){
		printf("ERROR: Could not open file");
		return -1;
	}
    
    /* 4. Check to see if the file opens. If it does not open, print out ERROR: Could not open file and end the program. */
    
	RouteRecord *records = createRecords(fileIn);
	int numRecords = fillRecords(records, fileIn);
	printf("Number of airline route combinations: %d\n", numRecords);
	fclose(fileIn);

    
    /* 5. Do the following to load the records into an array of RouteRecords
    	
    		5.1 Call createRecords(), which will read through the file once to find the total number of lines/records in the file. Use this count, to dynamically allocate memory for an array of RouteRecords. It returns a pointer to that array. Don't forget to rewind the file pointer.
    		
    		5.2 Call fillRecords() to go through the CSV file again to fill in the values. It will then return the actual number of items the array has. Recall that not all records in the original CSV file will be entered into the array. Print the number of unique routes operated by different airlines: Unique routes operated by airlines: ???
    		
    		5.3 Close the the file.
    */

	while(1){
		
		printMenu();

		if(scanf("%d", &menuInput) != 1){
			printf("Invalid Input.\n");
			scanf("%s", input1);
			continue;
		}else if(menuInput > 5 || menuInput < 1){
			printf("Invalid Input.\n");
			continue;
		}
		
		switch(menuInput){
			case 1:
				printf("Enter origin: ");
				scanf("%3s", input1);
				printf("Enter destination: ");
				scanf("%3s", input2);
				searchRecords(records, numRecords, input1, input2, ROUTE);
				break;
			case 2:
				printf("Enter origin: ");
				scanf("%3s", input1);
				searchRecords(records, numRecords, input1, NULL, ORIGIN);
				break;
			case 3: 
				printf("Enter destination: ");
				scanf("%3s", input1);
				searchRecords(records, numRecords, input1, NULL, DESTINATION);
				break;
			case 4:
				printf("Enter airline: ");
				scanf("%2s", input1);
				searchRecords(records, numRecords, input1, NULL, AIRLINE);
				break;
			case 5:
				printf("Quitting Program . . .");
				free(records);
				return 0;
		}
	}
    
    /* 6. Create an infinite loop that will do the following:
    
    		6.1 Call printMenu()
    		
    		6.2 Ask the user to input a value for the menu
    		
    		6.3 Handle the case in which a non-integer value is entered
    		
    		6.4 Create a switch/case statement to handle all the menu options
    		
	    		6.4.1 Each option requires the user to enter a search key
	    		
	    		6.4.2 Quit needs to free the array
    
    */
}
