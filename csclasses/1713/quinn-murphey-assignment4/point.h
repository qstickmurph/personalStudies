#ifndef POINT_H
#define POINT_H

typedef struct _Point
{
	double* coordinates;
}Point;
void InputPoints(Point *points, int dimension);
double ComputeDistance(Point *points, int dimension);
Point FindMidpoint(Point *points, int dimension);

#endif
