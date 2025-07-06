/**
 * CCDSALG MCO1 GROUP 23
 * Description: a program that computes the convex hull of 2D points using Graham’s Scan with selectionSort.
 * Authors:
 * Laborada, Nathan
 * Lee, Ashley Fiona
 * Villorente, Khyle Raeke
 */

#include "driver-helper.h"
#include "graham-helper.h"

/**
 * This is the main function for running the convex hull program.
 * It asks the user for filenames, reads the points from a file,
 * then calls grahamScan1(), which uses selectionSort, to compute the convex hull.
 *
 * @return 0 if it runs successfully, 1 otherwise
 */
int main() {
    Filename inputFilename, outputFilename; 
    Point points[MAX_STACK_SIZE];
    Stack hull;
    int n;
    int i;

    // Ask user for input and output filenames
    printf("Enter the filename to import points from: ");
    scanf("%s", inputFilename);
    printf("Enter the filename to export points to: ");
    scanf("%s", outputFilename);
    
    // Read points from the input file
    importInput(inputFilename, points, &n);

    if (n <= 0) {
        printf("ERROR: No valid points to process. Terminating process.\n");
        return 1;
    }
    printf("Successfully read %d points from %s.\n", n, inputFilename);

    // Compute convex hull using Graham's Scan (selection sort)
    grahamScan1(points, n, &hull);

    // Display convex hull points
    printf("Convex hull points:\n");
    for (i = 0; i < hull.top + 1; i++)
    {
        printf("Point %d: (%f, %f)\n", i + 1, hull.data[i].x, hull.data[i].y);
    }

    // Export convex hull points to the output file
    exportInput(outputFilename, hull.data, hull.top + 1);

    printf("Convex hull computation completed successfully.\n");

    return 0;
}
