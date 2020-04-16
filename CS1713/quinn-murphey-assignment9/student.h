#ifndef STUDENT_H
#define STUDENT_H

typedef struct Student
{
	int id;
    char name[10];
    int age;
    double gpa;
} Student;

Student *getStudentInformation(FILE *inFile, int *length);
void sortStudents(Student *students, int length);
int searchStudent(Student *students, int min, int max, int key);

#endif
