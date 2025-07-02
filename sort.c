/**
 * CCDSALG MCO1 GROUP 23
 * Description: a program that will compute the convex hull of a given set of 2D points using the Graham’s Scan algorithm.
 * Authors:
 * Laborada, Nathan
 * Lee, Ashley Fiona
 * Villorente, Khyle Raeke
 */

#include "sort.h"

/*
 * This function calculates the polar angle from an anchor point to another point
 * using the atan2 function. The angle is measured counterclockwise from the 
 * positive x-axis direction.
 *
 * @param anchor The reference point (origin) from which the angle is measured
 * @param p The target point to which the angle is calculated
 * 
 * @return The polar angle in degrees
 */
double solvePolarAngle(Point anchor, Point p) {
    double dx = p.x - anchor.x;
    double dy = p.y - anchor.y;
    
    return atan2(dy, dx) * 180.0 / PI; 
}

/*
 * This function calculates the squared distance between an anchor point
 * and another point. Uses squared distance to avoid expensive sqrt() operation
 * while maintaining relative ordering for comparison purposes.
 *
 * @param anchor The reference point from which distance is measured
 * @param p The target point to which distance is calculated
 * 
 * @return The squared distance between the two points (dx² + dy²)
 */
double solveDistance(Point anchor, Point p){
    double dx = p.x - anchor.x;
    double dy = p.y - anchor.y;
    
    return dx * dx + dy * dy;
}

/*
 * This function finds the anchor point for Graham scan algorithm by locating
 * the point with the lowest y-coordinate. If multiple points have the same
 * lowest y-coordinate, it selects the leftmost one (smallest x-coordinate).
 * The anchor point is moved to index 0 of the array.
 *
 * @param points Array of points to search through
 * @param n Number of points in the array
 * 
 * @return The anchor point (lowest y, then leftmost x)
 */
Point findAnchorPoint(Point points[], int n) {
    Point anchor = points[0];
    int anchorIndex = 0;
    
    for (int i = 1; i < n; i++) {
        if (points[i].y < anchor.y || 
            (points[i].y == anchor.y && points[i].x < anchor.x)) {
            anchor = points[i];
            anchorIndex = i;
        }
    }
    
    if (anchorIndex != 0) {
        Point temp = points[0];
        points[0] = points[anchorIndex];
        points[anchorIndex] = temp;
    }
    
    return anchor;
}

/*
 * This function compares two points relative to an anchor point for sorting
 * purposes in Graham scan. Points are compared first by polar angle, then
 * by distance if angles are equal.
 *
 * @param anchor The reference point for angle and distance calculations
 * @param p1 First point to compare
 * @param p2 Second point to compare
 * 
 * @return -1 if p1 < p2, 
 *          1 if p1 > p2, 
 *          0 if p1 == p2 (Comparing by angle first, then by distance)
 */
int comparePoints(Point anchor, Point p1, Point p2) {
    double angle1 = solvePolarAngle(anchor, p1);
    double angle2 = solvePolarAngle(anchor, p2);
    
    double distance1 = solveDistance(anchor, p1);
    double distance2 = solveDistance(anchor, p2);
    
    if (angle1 < angle2) {
        return -1;
    } else if (angle1 > angle2) {
        return 1;
    }
    
    // If angles are equal, compare distances
    if (distance1 < distance2) {
        return -1; 
    } else if (distance1 > distance2) {
        return 1; 
    }
    
    // Points are equal in both angle and distance 
    return 0; 
}

/*
 * This function swaps two Point structures by exchanging their values.
 * Used as a helper function for sorting algorithms.
 *
 * @param p1 Pointer to the first point to swap
 * @param p2 Pointer to the second point to swap
 */
void swapPoints(Point *p1, Point *p2) {
    Point temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}

/*
 * This function partitions an array segment for quicksort by selecting the
 * last element as pivot and rearranging elements so that smaller elements
 * are on the left and larger elements are on the right of the pivot.
 *
 * @param points Array of points to partition
 * @param low Starting index of the segment to partition
 * @param high Ending index of the segment (pivot element)
 * @param anchor Reference point for comparing points
 * 
 * @return The final position of the pivot element after partitioning
 */
int partition(Point points[], int low, int high, Point anchor){
    Point pivot = points[high];
    int i = low - 1;
    int j;

    for (j = low; j < high; j++){
        if (comparePoints(anchor, points[j], pivot) <= 0){
            i++;
            swapPoints(&points[i], &points[j]);
        }
    }

    swapPoints(&points[i + 1], &points[high]);
    return i + 1;
}

/*
 * This function implements selection sort algorithm to sort points by polar
 * angle relative to an anchor point. It's the "slow" sorting method with
 * O(n²) time complexity, used for comparison with quicksort.
 *
 * @param points Array of points to sort (anchor should be at index 0)
 * @param n Total number of points in the array
 * @param anchor Reference point for polar angle calculations
 */
void selectionSort(Point points[], int n, Point anchor) {
    for (int i = 1; i < n - 1; i++) {
        int minIndex = i;

        for (int j = i + 1; j < n; j++) {
            if (comparePoints(anchor, points[j], points[minIndex]) < 0) {
                minIndex = j;
            }
        }

        if (minIndex != i) {
            swapPoints(&points[i], &points[minIndex]);
        }
    }
}

/*
 * This function implements an iterative quicksort algorithm using a stack
 * to sort points by polar angle relative to an anchor point. It's the "fast"
 * sorting method with average O(n log n) time complexity.
 *
 * @param points Array of points to sort (anchor should be at index 0)
 * @param n Total number of points in the array
 * @param anchor Reference point for polar angle calculations
 */
void quickSort(Point points[], int n, Point anchor){
    if (n <= 1) return;
    
    int stack[2 * n]; 
    int top = -1;
    int high, low, pi;
    
    stack[++top] = 1;      
    stack[++top] = n - 1; 
    
    while (top >= 0) {
        high = stack[top--];
        low = stack[top--];
        
        if (low < high) {
            pi = partition(points, low, high, anchor);
            
            if (pi - 1 > low) {
                stack[++top] = low;
                stack[++top] = pi - 1;
            }

            if (pi + 1 < high) {
                stack[++top] = pi + 1;
                stack[++top] = high;
            }
        }
    }
}