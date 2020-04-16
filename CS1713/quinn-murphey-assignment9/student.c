#include <stdio.h> 
#include <string.h> 
#include <stdlib.h>
#include "student.h"

Student *getStudentInformation(FILE *inFile, int *length)
{
	char buffer[500];
	
	printf("\tCalculating length\n");
	
	while(fgets(buffer, 499, inFile) != 0){ //count lines after first
		*length += 1;
	}
	
	printf("\tAllocating memory for students\n");
	Student *students = (Student*)(malloc(sizeof(Student) * *length)); //dynamically initialize RouteRecord array

	printf("\tRewinding inFile\n");
	rewind(inFile); //set seek to first line

	int entryNumber = 0;
	
	printf("\tSetting file values to students\n");
	while(fgets(buffer, 500, inFile) != 0){ //reads each line after the first
		int id, age;
		char name[10];
		double gpa;
		
		if (4 != sscanf(buffer, "%d,%[^,],%d,%lf", &id, name, &age, &gpa)){ //skips line if incorrectly formatted
			continue;
		}

		students[entryNumber].id = id;
		strcpy(students[entryNumber].name, name);
		students[entryNumber].age = age;
		students[entryNumber].gpa = gpa;

		entryNumber++;
	}
		
	return students;
}


void sortStudents(Student *students, int length)
{
	int suffixStart = 0;
    while(suffixStart != length){
        //look at each element in suffix
        for(int i = suffixStart; i < length; ++i){
            if(students[i].id < students[suffixStart].id){
                Student temp = students[i];
				students[i] = students[suffixStart];
				students[suffixStart] = temp;
			}
		}
        suffixStart += 1;
	}
}

int searchStudent(Student *students, int min, int max, int key)
{
	if(min == max){ 
		if(students[min].id == key){
        	return min;
		}
		return -1;
	}

    int mid = (min + max) / 2;

    if(students[mid].id == key){
		return mid;
	}else if(students[mid].id > key){
        if(min == mid){ //nothing left to search
            return -1;
		}
        else{
            return searchStudent(students, min, mid - 1, key); //search segment between min and mid - 1
		}
	}else{
        return searchStudent(students, mid + 1, max, key);
	}

	return -1;
}
