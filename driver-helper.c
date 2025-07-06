/**
 * CCDSALG MCO1 GROUP 23
 * Description: a program that will compute the convex hull of a given set of 2D points using the Graham’s Scan algorithm.
 * Authors:
 * Laborada, Nathan
 * Lee, Ashley Fiona
 * Villorente, Khyle Raeke
 */

 #include "driver-helper.h"


/*
 * This function reads point data from a text file and stores it in an array.
 * The file format should have the number of points on the first line, followed
 * by coordinate pairs (x y) on subsequent lines. Validates that coordinates
 * are non-negative and handles various error conditions.
 *
 * @param filename The name of the input file to read from
 * @param points Array to store the loaded Point structures
 * @param n Pointer to integer that will store the number of points read
 */
void importInput(Filename filename, Point points[], int *n) {
    FILE *file = fopen(filename, "r");

    if (file == NULL) {
        printf("ERROR: %s does not exist.\n", filename); // Error mesage for invalid Filename
        *n = 0;
        return;
    }
    else if(fscanf(file, "%d", n) != 1) {
            printf("ERROR: Could not read the number of points from %s.\n", filename); //Error message when no number of points are read
            fclose(file);
            *n = 0;
            return;
        }
        else if (*n <= 0) {
            printf("ERROR: The number of points must be greater than zero.\n"); //Error message when number of points is equal to zero
            fclose(file);
            *n = 0;
            return;
        }

        for (int i = 0; i < *n; i++) 
        {
            if (fscanf(file, "%lf %lf", &points[i].x, &points[i].y) != 2) 
            {
                printf("ERROR: Could not read point %d from %s.\n", i + 1, filename); //Error message for when a point is not read
                fclose(file);
                *n = i;
                return;
            }
        }
        
    fclose(file);
}

/*
 * This function displays an array of points in a formatted manner with a
 * descriptive title. Each point is shown with its index number and coordinates
 * rounded to 2 decimal places for readability.
 *
 * @param points Array of Point structures to display
 * @param n Number of points in the array to display
 * @param title Descriptive string to print as a header before the points
 */
void displayPoints(Point points[], int n, const char* title) {
    printf("\n%s:\n", title);
    for (int i = 0; i < n; i++) {
        printf("Point %d: (%.6f, %.6f)\n", i + 1, points[i].x, points[i].y);
    }
}


void exportInput(Filename filename, Point points[], int n) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("ERROR: Could not open %s for writing.\n", filename);
        return;
    }
    fprintf(file, "%d\n", n);
    for (int i = 0; i < n; i++) {
        fprintf(file, "%.6f %.6f\n", points[i].x, points[i].y);
    }
    fclose(file);
    printf("Successfully exported %d points to %s.\n", n, filename);
}

