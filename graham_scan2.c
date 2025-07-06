/**
 * CCDSALG MCO1 GROUP 23
 * Description: a program that will compute the convex hull of a given set of 2D points using the Graham’s Scan algorithm.
 * Authors:
 * Laborada, Nathan
 * Lee, Ashley Fiona
 * Villorente, Khyle Raeke
 */

 #include "graham-helper.h"

/*
 * This function calculates the cross product of vectors OA and OB to determine
 * the orientation of three points. Used to check if points make a left turn,
 * right turn, or are collinear.
 *
 * @param O Origin point
 * @param A Second point
 * @param B Third point
 * @return Positive if counter-clockwise, negative if clockwise, zero if collinear
 */
double crossProduct(Point O, Point A, Point B) {
    return (A.x - O.x) * (B.y - O.y) - (A.y - O.y) * (B.x - O.x);
}

/*
 * This function implements the Graham scan algorithm to find the convex hull
 * of a set of points. The algorithm sorts points by polar angle relative to
 * the anchor point, then uses a stack to maintain the convex hull vertices.
 *
 * @param points Array of points (sorted by polar angle)
 * @param n Number of points in the array
 * @param hull Pointer to stack that will store the convex hull vertices
 * @return None (void function, fills the hull stack)
 */
void grahamScan2(Point points[], int n, Stack *hull) {
    clock_t the_start; // start time 
    clock_t the_end;   // end time
    int i;

    the_start = clock();

    Point anchor = findAnchorPoint(points, n);
    quickSort(points, n, anchor);
    
    if (n < 3) {
        printf("Error: Need at least 3 points for convex hull\n");
        CREATE(hull);
        return;
    }
    
    // Initialize the stack
    CREATE(hull);
    
    // Push first two points (anchor and first sorted point)
    PUSH(hull, points[0]);  // Anchor point
    PUSH(hull, points[1]);  // First point sorted by polar angle
    
    // Process remaining points
    for (i = 2; i < n; i++) {
        // Remove points that make clockwise turn (right turn)
        while (hull->top >= 1) {
            Point top = TOP(hull);
            Point nextToTop = NEXTTOTOP(hull);
            
            // Calculate cross product to determine turn direction
            double cp = crossProduct(nextToTop, top, points[i]);
            
            if (cp > 0) {
                // Counter-clockwise turn (left turn) - keep the point
                break;
            }
            
            // Clockwise turn (right turn) - remove the top point
            POP(hull);
        }
        
        // Push current point to the hull
        PUSH(hull, points[i]);
    }

    the_end = clock();
    double time_taken = ((double)(the_end - the_start));
    printf("Number of points: %6d Time Elapsed: %15.9lf seconds\n", n, time_taken);   
}