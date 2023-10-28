#include<graphics.h>
#include<math.h>
#include<conio.h>
#include<stdio.h>

void main()
{
    // Declare arrays to store control points
    int x[4], y[4], i;

    // Variables for computing the points on the Bezier curve
    double put_x, put_y, t;

    // Initialize graphics mode
    int gr = DETECT, gm;
    initgraph(&gr, &gm, "C:\\TURBOC3\\BGI");

    // Prompt user to enter control points
    printf("\n*** Bezier Curve ****");
    printf("\n Please enter x and y coordinates ");
    for (i = 0; i < 4; i++)
    {
        scanf("%d%d", &x[i], &y[i]);
        putpixel(x[i], y[i], 3); // Plot control points
    }

    // Calculate points on the Bezier curve and plot them
    for (t = 0.0; t <= 1.0; t = t + 0.001) // t always lies between 0 and 1
    {
        // Bezier curve formula for x and y
        put_x = pow(1 - t, 3) * x[0] + 3 * t * pow(1 - t, 2) * x[1] + 3 * t * t * (1 - t) * x[2] + pow(t, 3) * x[3];
        put_y = pow(1 - t, 3) * y[0] + 3 * t * pow(1 - t, 2) * y[1] + 3 * t * t * (1 - t) * y[2] + pow(t, 3) * y[3];

        putpixel(put_x, put_y, WHITE); // Plot points on the curve
    }

    // Wait for a key press before closing the graphics window
    getch();
    closegraph();
}
