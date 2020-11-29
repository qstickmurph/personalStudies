#include <stdio.h>
#include "point.h"
#include <stdlib.h>

int main(int argc, char *argv[])
{
	printf("Please input the number of points you plan on using. For default assignment, input 2.\n");
	int inputInt;
	scanf("%d", &inputInt);
	printf("Point 1's coordinates will be denoted x0, x1, ... and Point 2 will be denoted y0, y1, ...\n");
	Point points[2];
	points[0].coordinates = (double*)malloc(sizeof(double) * inputInt);
	points[1].coordinates = (double*)malloc(sizeof(double) * inputInt);
	InputPoints(points, inputInt);
	
//	points[0].coordinates[0] = 13;
//	points[0].coordinates[1] = 12;
	printf("Point 1: ");
	for(int i = 0; i < inputInt; ++i)
	{
		printf("\t%lf,", points[0].coordinates[i]);
	}
	printf("\n");
	printf("Point 2: ");
	for(int i = 0; i < inputInt; ++i)
	{
		printf("\t%lf,", points[1].coordinates[i]);
	}
	printf("\n");
	
	double dist = ComputeDistance(points, inputInt);
	Point midpoint = FindMidpoint(points, inputInt);
	
	printf("Distance = %lf\n", dist);
	printf("Midpoint: ");
	for(int i = 0; i < inputInt; ++i)
	{
		printf("\t%lf,", midpoint.coordinates[i]);
	}
	printf("\n");

	free(points[0].coordinates);
	free(points[1].coordinates);
	free(midpoint.coordinates);

	return 0; 
}
