#include <math.h>
#include "stack.h"

#define PI 3.14159265358979323846

double solvePolarAngle(Point anchor, Point p);
Point findAnchorPoint(Point points[], int n);
int comparePoints(Point anchor, Point p1, Point p2);
void swapPoints(Point *p1, Point *p2);
int partition(Point points[], int low, int high, Point anchor);
void selectionSort(Point points[], int n, Point anchor);
void quickSort(Point points[], int n, Point anchor);