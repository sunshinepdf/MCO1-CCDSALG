/**
 * CCDSALG MCO1 GROUP 23
 * Description: a program that will compute the convex hull of a given set of 2D points using the Graham’s Scan algorithm.
 * Authors:
 * Laborada, Nathan
 * Lee, Ashley Fiona
 * Villorente, Khyle Raeke
 */

#include <stdio.h>
#include <time.h>  

#include "sort.c"
#include "stack.h"

typedef char Filename[100];

void importInput(Filename filename, Point points[], int *n);
void displayPoints(Point points[], int n, const char* title);
void displayExecutionTime(clock_t start, clock_t end);