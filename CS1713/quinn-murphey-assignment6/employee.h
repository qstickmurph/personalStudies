#ifndef EMPLOYEE_H
#define EMPLOYEE_H

typedef struct Employee
{
	char name[11];
	int id;
	double salary;
}Employee;
Employee getEmployeeWithHighestSalary(Employee *employees, int numEmployees);



#endif
