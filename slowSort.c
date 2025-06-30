#include "slowSort.h"

double solvePolarAngle (double x1, double y1, double x2, double y2) {
    double dx = x2 - x1;
    double dy = y2 - y1;
    
    return atan2(dy, dx) * 180.0/PI; 
}

void selectionSort(){
    // Implementation here
}
