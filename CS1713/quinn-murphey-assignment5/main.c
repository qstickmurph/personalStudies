#include <stdio.h>

int PrintTriangle(int n)
{
	//Each loop constructs a row
	for(int i = 0; i < n; ++i)
	{
		//print preliminary spaces
		for(int j = 0; j < (2*(n-i) + 1)/2; ++j)
		{
			printf(" ");
		}

		//print numbers + space
		for(int j = 0; j <= i; ++j)
		{
			//find i!
			unsigned long long ifac = 1;
			for(int k = i; k > 0; --k)
			{
				ifac *= k;
			}
			
			//find j!
			unsigned long long jfac = 1;
			for(int k = j; k > 0; --k)
			{
				jfac *= k;
			}
			
			//find i-j!
			unsigned long long ijfac = 1;
			for(int k = i-j; k > 0; --k)
			{
				ijfac *= k;
			}

			//print i!/((j!)((i-j)!))
			printf("%lld ", ifac/(jfac*ijfac));
		}

		//print new line
		printf("\n");
	}	
}

int main(int argc, char *argv[])
{
	int n;
	printf("How many rows of pascal's triangle would you like to output?");
	scanf("%d", &n);
	PrintTriangle(n);
}
