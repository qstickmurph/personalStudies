#ifndef STUDENT_H 
#define STUDENT_H 


typedef struct Student {     // Define elements for each Student Node 
	int id;
	char name[11];
	double gpa;
	struct Student *next;
} Student; 

void print(Student *s);

Student *insertStudentSortedByName(Student *s, Student *new);

void Split(Student *head, Student **frontRef, Student **backRef);

Student *Merge(Student *a, Student *b);
	
void sortListByID(Student **headRef);

#endif
