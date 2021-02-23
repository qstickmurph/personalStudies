#include "employee.h"

Employee getEmployeeWithHighestSalary(Employee *employees, int totalEmployees)
{
	int maxIndex = 0;
	for(int i = 0; i < totalEmployees; ++i)
			if((employees + i)->salary > (employees + maxIndex)->salary)
					maxIndex = i;
	return *(employees + maxIndex);	


}
