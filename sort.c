#include "sort.h"

double solvePolarAngle(Point anchor, Point p) {
    double dx = p.x - anchor.x;
    double dy = p.y - anchor.y;
    
    return atan2(dy, dx) * 180.0 / PI; 
}

double solveDistance(Point anchor, Point p){
    double dx = p.x - anchor.x;
    double dy = p.y - anchor.y;
    
    return dx * dx + dy * dy;
}

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

int comparePoints(Point anchor, Point p1, Point p2) {
    double angle1 = solvePolarAngle(anchor, p1);
    double angle2 = solvePolarAngle(anchor, p2);
    
    double distance1 = solveDistance(anchor, p1);
    double distance2 = solveDistance(anchor, p2);
    
    if (angle1 < angle2) {
        return -1; // p1 is closer to the anchor in polar angle
    } else if (angle1 > angle2) {
        return 1; // p2 is closer to the anchor in polar angle
    }
    
    // If angles are equal, compare distances
    if (distance1 < distance2) {
        return -1; // p1 is closer to the anchor in distance
    } else if (distance1 > distance2) {
        return 1; // p2 is closer to the anchor in distance
    }
    
    return 0; // Points are equal in both angle and distance
}

void swapPoints(Point *p1, Point *p2) {
    Point temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}

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

void selectionSort(Point points[], int n, Point anchor) {
    // Start from index 1 since anchor is at index 0
    for (int i = 1; i < n - 1; i++) {
        int minIndex = i;

        for (int j = i + 1; j < n; j++) {
            if (comparePoints(anchor, points[j], points[minIndex]) < 0) {
                minIndex = j;
            }
        }
        
        // Swap if we found a smaller element
        if (minIndex != i) {
            swapPoints(&points[i], &points[minIndex]);
        }
    }
}

void quickSort(Point points[], int n, Point anchor){
    if (n <= 1) return;
    
    int stack[2 * n]; 
    int top = -1;
    
    stack[++top] = 1;      // low
    stack[++top] = n - 1;  // high
    
    while (top >= 0) {
        // Pop range from stack
        int high = stack[top--];
        int low = stack[top--];
        
        if (low < high) {
            int pi = partition(points, low, high, anchor);
            
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