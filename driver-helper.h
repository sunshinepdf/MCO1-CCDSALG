/**
 * CCDSALG MCO1 GROUP 23
 * Description: a program that will compute the convex hull of a given set of 2D points using the Graham's Scan algorithm.
 * Authors:
 * Laborada, Nathan
 * Lee, Ashley Fiona
 * Villorente, Khyle Raeke
 */

#ifndef DRIVER_HELPER_H
#define DRIVER_HELPER_H

#include <stdio.h>
#include "stack.h"

typedef char Filename[100];

void importInput(Filename filename, Point points[], int *n);
void displayPoints(Point points[], int n, const char* title);
void exportInput(Filename filename, Point points[], int n);

#endif