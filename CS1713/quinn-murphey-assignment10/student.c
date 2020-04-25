#include<stdio.h> 
#include<string.h> 
#include"student.h"

//Print the linked list in order, starting from the “head”. For each student node, you need to print all the elements. 
void print(Student *s){
	printf("Id: %d, Name: %s, Gpa: %lf\n", s->id, s->name, s->gpa);
	if(s->next != NULL){
		print(s->next);
	}
}
// Create and insert new nodes in the linked list. The insertion should happen in alphabetical order of the name. The values are for each student insertion are passed into this function from the main, where the values are read from a file. 
void insertStudentSortedByName(Student *s){

}
// Sort the linked list in increasing order of the student-id (integer), using any sorting algorithm.
void sortListByID(Student *s){
	
}
