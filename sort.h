/**
 * CCDSALG MCO1 GROUP 23
 * Description: a program that will compute the convex hull of a given set of 2D points using the Graham's Scan algorithm.
 * Authors:
 * Laborada, Nathan
 * Lee, Ashley Fiona
 * Villorente, Khyle Raeke
 */

#ifndef SORT_H
#define SORT_H

#include <math.h>
#include "stack.h"

#define PI 3.14159265358979323846

double solvePolarAngle(Point anchor, Point p);
double solveDistance(Point anchor, Point p);
Point findAnchorPoint(Point points[], int n);
int comparePoints(Point anchor, Point p1, Point p2);
void swapPoints(Point *p1, Point *p2);
int partition(Point points[], int low, int high, Point anchor);
void selectionSort(Point points[], int n, Point anchor);
void quickSort(Point points[], int n, Point anchor);

#endif