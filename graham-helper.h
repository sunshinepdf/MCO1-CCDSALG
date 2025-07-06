#ifndef GRAHAM_HELPER_H
#define GRAHAM_HELPER_H

#include <stdio.h>
#include <time.h>  
#include "sort.h"
#include "stack.h"

void grahamScan1(Point points[], int n, Stack *hull);
void grahamScan2(Point points[], int n, Stack *hull);
double crossProduct(Point O, Point A, Point B);

#endif