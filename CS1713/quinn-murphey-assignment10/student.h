#ifndef STUDENT_H 
#define STUDENT_H 


typedef struct Student {     // Define elements for each Student Node 
	int id;
	char name[11];
	double gpa;
	struct Student *next;
} Student; 

void print(Student *s);

void insertStudentSortedByName(Student *s);

void sortListByID(Student *s);

#endif
