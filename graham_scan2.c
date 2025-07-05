/**
 * CCDSALG MCO1 GROUP 23
 * Description: a program that will compute the convex hull of a given set of 2D points using the Graham’s Scan algorithm.
 * Authors:
 * Laborada, Nathan
 * Lee, Ashley Fiona
 * Villorente, Khyle Raeke
 */

#include "driver-helper.c"

int main() {
    Filename filename; 
    Point points[MAX_STACK_SIZE];
    int n;

    printf("Enter the filename to import points from: ");
    scanf("%s", filename);
    
    importInput(filename, points, &n);

    if (n > 0) {
        printf("Successfully read %d points from %s.\n", n, filename);
        
        // Display original points
        displayPoints(points, n, "Original Points");
        
        // Test 1: Find the lowest point (anchor)
        printf("\n=== Testing findLowestPoint() ===\n");
        Point anchor = findAnchorPoint(points, n);
        printf("Lowest point (anchor): (%.2f, %.2f)\n", anchor.x, anchor.y);
        
        // Display points after finding anchor (anchor should now be at index 0)
        displayPoints(points, n, "Points after finding anchor");
        
        // Test 2: Test polar angle calculation
        printf("\n=== Testing solvePolarAngle() ===\n");
        for (int i = 1; i < n; i++) {
            double angle = solvePolarAngle(anchor, points[i]);
            printf("Polar angle from anchor (%.2f, %.2f) to point (%.2f, %.2f): %.2f degrees\n", 
                   anchor.x, anchor.y, points[i].x, points[i].y, angle);
        }

        //Test 4: Sort points using quicksort
        printf("\n=== Testing quickSort() ===\n");
        quickSort(points, n, anchor);
        displayPoints(points, n, "Points sorted by polar angle using quicksort");
    }

    return 0;
}
