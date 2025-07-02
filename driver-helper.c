#include "driver-helper.h"

void importInput(Filename filename, Point points[], int *n) {
    FILE *file = fopen(filename, "r");

    if (file == NULL) {
        printf("ERROR: %s does not exist.\n", filename);
        *n = 0;
        return;
    }
    else if(fscanf(file, "%d", n) != 1) {
            printf("ERROR: Could not read the number of points from %s.\n", filename);
            fclose(file);
            *n = 0;
            return;
        }
        else if (*n <= 0) {
            printf("ERROR: The number of points must be greater than zero.\n");
            fclose(file);
            *n = 0;
            return;
        }

        for (int i = 0; i < *n; i++) 
        {
            if (fscanf(file, "%lf %lf", &points[i].x, &points[i].y) != 2) 
            {
                printf("ERROR: Could not read point %d from %s.\n", i + 1, filename);
                fclose(file);
                *n = i;
                return;
            }
            else if (points[i].x < 0 || points[i].y < 0) 
            {
                printf("ERROR: Coordinates must be non-negative for point %d.\n", i + 1);
                fclose(file);
                *n = i;
                return;
            }

    }
    fclose(file);
}

void displayPoints(Point points[], int n, const char* title) {
    printf("\n%s:\n", title);
    for (int i = 0; i < n; i++) {
        printf("Point %d: (%.2f, %.2f)\n", i + 1, points[i].x, points[i].y);
    }
}

