#include <stdio.h>
#include <stdlib.h>
#include "employee.h"


int main(int argc, char *argv[])
{
	FILE* inFile = NULL;
	inFile = fopen("inputData.txt", "r");
	if(inFile == NULL)
	{
		printf("Could not find/open file\n");
		return -1;
	}
	
	int numEmployees = 0;

	for (char c = getc(inFile); c != EOF; c = getc(inFile)) 
        if (c == '\n') // Increment count if this character is newline 
            numEmployees += 1; 
	
	rewind(inFile);

	Employee *employeesList;
	employeesList = (Employee*)malloc(sizeof(Employee)*numEmployees);

	
	for(int i = 0; i < numEmployees; ++i)
	{
		fscanf(inFile, "%10s", (employeesList + i)->name);
		fscanf(inFile, "%d", &(employeesList + i)->id);
		fscanf(inFile, "%lf", &(employeesList + i)->salary);
	}
	fclose(inFile);
	
	Employee highestPaid = getEmployeeWithHighestSalary(employeesList, numEmployees);
	FILE* outFile = NULL;
	outFile = fopen("outputData.txt", "w+");
	
	fprintf(outFile, "%s %d %lf", highestPaid.name, highestPaid.id, highestPaid.salary);
	fclose(outFile);
}
