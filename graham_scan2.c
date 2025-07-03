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
        displayPoints(points, n, "Original Points"); //display original points

        // Measure time for Graham’s Scan (fast version)
        clock_t start = clock();
        grahamScanQuick(points, n);
        clock_t end = clock();

        double elapsed = (double)(end - start) * 1000.0 / CLOCKS_PER_SEC;
        printf("\nElapsed time (Fast version - quickSort): %.2f ms\n", elapsed);
    } else {
        printf("Error: No points found in the file or failed to read input.\n");
    }

    return 0;
}
