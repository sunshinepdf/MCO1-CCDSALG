#include "driver-helper.h"
#include "graham-helper.h"

int main() {
    Filename inputFilename, outputFilename; 
    Point points[MAX_STACK_SIZE];
    Stack hull;
    int n;
    int i;

    printf("Enter the filename to import points from: ");
    scanf("%s", inputFilename);
    printf("Enter the filename to export points to: ");
    scanf("%s", outputFilename);
    
    importInput(inputFilename, points, &n);

    if (n <= 0) {
        printf("ERROR: No valid points to process. Terminating process.\n");
        return 1;
    }
    printf("Successfully read %d points from %s.\n", n, inputFilename);

    grahamScan2(points, n, &hull);

    printf("Convex hull points:\n");
    for (i = 0; i < hull.top + 1; i++)
    {
        printf("Point %d: (%f, %f)\n", i + 1, hull.data[i].x, hull.data[i].y);
    }

    exportInput(outputFilename, hull.data, hull.top + 1);

    printf("Convex hull computation completed successfully.\n");

    return 0;
}