#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"student.h"

int main(int argc, char *argv[]) {

	FILE *inFile;
	char buffer[1000];

	if(argc != 2){
		printf("usage: runMe <fileName>\n");
		return -1;
	}
	
	inFile = fopen(argv[1], "r");
	if(inFile == NULL){
		printf("Invalid file name\n");
		return -1;
	}
	
	Student *head;
	while(fgets(buffer, 1000, inFile) != NULL){
		Student *new = (Student*)(malloc(sizeof(Student)));
		if (3 != sscanf(buffer, "%d,%[^,],%lf", &(new->id), new->name, &(new->gpa))){// skips if incorrectly formatted
			continue;
		}
		if(head == NULL){
			head = new;
		}else{
			head = insertStudentSortedByName(head, new);
		}
	}

	printf("Students sorted by name: \n");
	print(head);
	printf("\n");

	sortListByID(&head);

	printf("Students sorted by id: \n");
	print(head);
	printf("\n");

	return 0; 
}
