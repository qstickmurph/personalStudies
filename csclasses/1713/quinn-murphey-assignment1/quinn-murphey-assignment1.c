#include <stdio.h>
#include <math.h>

//gcc quadraticFormula.c -lm 

double * positiveDiscDec(double a,double b,double c)
{
	static double root[2];
	root[0] = (-b + sqrt(b*b-4*a*c))/(2*a);
	root[1] = (-b - sqrt(b*b-4*a*c))/(2*a);
	return root;
}

double * negativeDiscDec(double a,double b,double c)
{
	static double root[2];

	root[0] = (-b)/(2*a);
	root[1] = sqrt(-(b*b - 4*a*c))/(2*a);
	return root;
}

double * positiveDiscSq(double a,double b,double c)
{
	static double coeff[8];


	return coeff;
}

double * negativeDiscSq(double a,double b,double c)
{
	static double coeff[8];
	
	return coeff;
}

int main(void)
{
	double a;
	double b;
	double c;
	int correct, YesOrNo, running;
	running = 1;
	// Getting proper inputs for a,b,c
	while(running==1)
	{	
		correct = 1;
		YesOrNo = 1;
		running = 1;
		printf("\nThis function caluclates the 2 roots of a quadratic polynomial of the form ax^2 + bx + c = 0.\n\n");
		while(correct == 1)
		{

			printf("Please enter the value for a:");
			scanf("%lf", &a);
			printf("\n");

			printf("Please enter the value for b:");
			scanf("%lf", &b);
			printf("\n");

			printf("Please enter the value for c:");
			scanf("%lf", &c);
			printf("\n");

			printf("You entered the following values:\na: %lf\nb: %lf\nc: %lf\n", a,b,c);
			printf("Is this correct? [Y/N]");

			YesOrNo = 1;
			while(YesOrNo == 1)
			{
				char c = getchar();
				switch(c)
				{
					case 'y':
					case 'Y':
						YesOrNo = 0;
						correct = 0;
						break;
					case 'n':
					case 'N':
						YesOrNo = 0;
						printf("\nResetting values . . .\n");	
						break;
				}
			}

		}
		
		// Calculating roots
		double disc = b*b - 4*a*c;
		int awn;
		if(a == 0)
		{
			printf("Please enter a nonzero value for a.\nResetting program. . .\n");
		}
		else
		{
			printf("\nWould you like an output in decimal approximation or exact format?\n");
			printf("(1) Decimal Approximation\n");
			printf("(2) Exact\n");
			
			scanf("%d", &awn);

			if(awn == 1)
			{	
				if(disc >= 0)
				{
					double *roots = positiveDiscDec(a,b,c);
					printf("\nThe roots of the polynomial %lfx^2 + %lfx + %lf = 0 are\n", a,b,c);
					printf("Root 1: %lf\n", *(roots));
					printf("Root 2: %lf\n", *(1+roots));
				}
				else
				{
					double *roots = negativeDiscDec(a,b,c);
					printf("\nThe roots of the polynomial %lfx^2 + %lfx + %lf = 0 are\n", a,b,c);
					printf("Root 1: %lf + %lfi \n", *(roots), *(roots+1));
					printf("Root 2: %lf - %lfi \n", *(roots), *(roots+1));
				}
			}
			else if(awn == 2)
			{
				printf("\nCurrently in development\n");	
				//double coeff[8];
			}
			else
			{
				printf("\nPlease enter a valid respose.\n");
			}
		}

		printf("\nWould you like to find the roots of another polynomial?\n");
		printf("(1) Yes\n");
		printf("(2) No\n");
		scanf("%d", &awn);

		if(awn == 1){
			running = 1;	

		}else{
			running = 0;
		}
	}
	return 0;
}

