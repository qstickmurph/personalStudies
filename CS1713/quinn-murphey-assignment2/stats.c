#include <stdio.h>
#include <math.h>

double ComputeAverage(double *list)
{
	double sum = 0;
	for(int i = 1; i <= list[0]; ++i)
	{
		sum += list[i];
	}
	return sum / *(list);
}

double StdDeviation(double *list, double avg)
{
	double sum = 0;
	for(int i = 1; i <= list[0]; ++i)
	{
		sum += (list[i] - avg)*(list[i] - avg);
	}
	return sqrt(sum/(list[0]-1));
}

void FillZScores(double *list, double stdDev, double avg, double *emptyList)
{
	for(int i = 0; i < list[0]; ++i)
	{
		emptyList[i] = (list[i + 1] - avg)/stdDev;
	}
}

int main(int argc, char *argv[])
{
	int N;
	printf("Enter N: ");
	scanf("%d", &N);
	
	double data[N+1];
	data[0] = (double) N;
	printf("Enter data: ");
	char ch;
	int i = 0;
	while(scanf("%c", &ch) && ch != '\n')
	{
		if(ch == ' ')
			continue;
		data[++i] = ch - '0';
	}	
	for(int i = 1; i <= N; ++i)
	{
		scanf("%lf", &data[i]);
	}

	double avg = ComputeAverage(data);
	double stdDev = StdDeviation(data, avg);
	double ZScores[N];
	FillZScores(data, stdDev, avg, ZScores);

	printf("Average: %lf\n", avg);
	printf("Standard Deviation: %lf\n", stdDev);
	printf("Z-Scores: ");
	for(int i = 0; i < N; ++i)
	{
		printf("%lf ", ZScores[i]);
	}
	printf("\n");
}
