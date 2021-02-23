#include <stdio.h>
#include "point.h"
#include <math.h>
#include <stdlib.h>

void InputPoints(Point *points, int dimension)
{
	for(int i = 0; i < dimension; ++i)
	{
		printf("Please input the value for x%d: ", i);
		scanf("%lf", &points[0].coordinates[i]);
	}
	for(int i = 0; i < dimension; ++i)
	{
		printf("Please input the value for y%d: ", i);
		scanf("%lf", &points[1].coordinates[i]);
	}
}

double ComputeDistance(Point *points, int dimension)
{
	int sum = 0;
	for(int i = 0; i < dimension; ++i)
	{
		sum += pow(points[1].coordinates[i] - points[0].coordinates[i], 2);
	}
	return sqrt(sum);
}

Point FindMidpoint(Point *points, int dimension)
{
	Point midpoint;
	midpoint.coordinates = (double*)malloc(sizeof(double) * dimension);
	for(int i = 0; i < dimension; ++i)
	{
		midpoint.coordinates[i] = (points[0].coordinates[i] + points[1].coordinates[i])/2;
	}
	
	return midpoint;
}
