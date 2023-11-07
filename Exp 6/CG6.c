#include<graphics.h>
#include<conio.h>
#include<math.h>

// Function to draw a Koch snowflake from point (x1, y1) to point (x2, y2) with a given number of iterations.
void koch(int x1, int y1, int x2, int y2, int it) {

  float angle;
  int x3,x4,x,y3,y4,y;
  // Calculate the angle of the Koch snowflake.
  angle = 60 * M_PI / 180;

  // Calculate the coordinates of the middle point of the Koch snowflake.
  x3 = (2 * x1 + x2) / 3;
  y3 = (2 * y1 + y2) / 3;

  // Calculate the coordinates of the fourth point of the Koch snowflake.
  x4 = (x1 + 2 * x2) / 3;
  y4 = (y1 + 2 * y2) / 3;

  // Calculate the coordinates of the fifth point of the Koch snowflake.
  x = x3 + (x4 - x3) * cos(angle) + (y4 - y3) * sin(angle);
  y = y3 - (x4 - x3) * sin(angle) + (y4 - y3) * cos(angle);

  // If the number of iterations is greater than 0, recursively draw four Koch snowflakes
  // from the four points of the current Koch snowflake.
  if (it > 0) {
    koch(x1, y1, x3, y3, it - 1);
    koch(x3, y3, x, y, it - 1);
    koch(x, y, x4, y4, it - 1);
    koch(x4, y4, x2, y2, it - 1);
  } else {

    // Otherwise, draw lines connecting the four points of the Koch snowflake.
    line(x1, y1, x3, y3);
    line(x3, y3, x, y);
    line(x, y, x4, y4);
    line(x4, y4, x2, y2);
  }
}

int main(void) {

  // Initialize the Turbo C graphics system.
  int gd = DETECT, gm, n, i;
  initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");

  // Prompt the user to enter the number of iterations.
  printf("Enter number of iterations: ");
  scanf("%d", &n);

  // Draw the Koch snowflake with a given number of iterations.
  for (i = 0; i < n; i++) {
    cleardevice();
    koch(100, 100, 400, 400, i);
    getch();
  }

  // Close the Turbo C graphics system.
  closegraph();

  return 0;
}