#include <stdio.h> 
#include <string.h> 
#include <stdlib.h>
#include "student.h"

int main(int argc, char *argv[])
{
	FILE *inFile = NULL;
	if(argc != 2){
		printf("Usage ./runMe [fileName]\n");
		return -1;
	}
	inFile = fopen(argv[1], "r");
	if(inFile == NULL){
		printf("Please enter a valid filename\n");
	}

	int length = 0;
	
	Student *students = getStudentInformation(inFile, &length);


	sortStudents(students, length);
	
	printf("The names for students in sorted order of their IDs are \n");
	for(int i=0; i<length; i++){
		printf("%s, ", students[i].name);
	}
	
	int inputID;
	printf("\nEnter student id : "); 
	scanf("%d", &inputID);

	int index = searchStudent(students, 0, length - 1, inputID);

	// If the student record is not found print “No student record found for inputID”
	// For the “studentFound” print the student information
	
	if(index == -1){
		printf("No student record found for %d\n", inputID);
	}
	else{
		Student studentFound = students[index];
		printf("Information of the found student is\n");
		printf("ID : %d\n", studentFound.id); 
		printf("Name : %s\n", studentFound.name); 
		printf("Age : %d\n", studentFound.age); 
		printf("GPA : %lf\n", studentFound.gpa);
	}

	return 0; 
}
