#include <stdio.h>
#include "arithmetic.h"

int main(int argc, char* argv[])
{
	int loop = 1;
	double value = 0.0;
	int input1;
	double input2;
	while(loop == 1)
	{
//		printf("Current value: %d\n", value);
		printf("Please choose an operation\n");
		printf("0) Exit\n");
		printf("1) Add\n");
		printf("2) Subtract\n");
		printf("3) Multiply\n");
		printf("4) Divide\n");
		scanf("%d", &input1);
		if(input1 == 0)
		{
			break;
		}
		printf("Please select a value\n");
		scanf("%lf", &input2);
		switch(input1)
		{
			case 1:
				value = Add(value, input2);
				break;
			case 2:
				value = Subtract(value, input2);
				break;
			case 3:
				value = Multiply(value, input2);
				break;
			case 4:
				value = Divide(value, input2);
				break;
			default:
				continue;
		}
		printf("Result: %lf\n", value);
	}
	
	
	
}
