#include <stdio.h>
#include <time.h>  

#include "sort.c"
#include "stack.h"

typedef char Filename[100];

//Functions for reading input text files
void importInput(Filename filename, Point points[], int *n);
void displayPoints(Point points[], int n, const char* title);
void displayExecutionTime(clock_t start, clock_t end);