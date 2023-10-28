#include <stdio.h>
#include <conio.h>
#include <graphics.h>
#include <math.h>

// Translates a rectangle from (x1, y1) to (xt, yt).
void translate(int x1, int y1, int x2, int y2, int xt, int yt) {
  int dx, dy;
  dx = xt - x1;
  dy = yt - y1;
  rectangle(xt, yt, x2 + dx, y2 + dy);
}

// Rotates a rectangle around its center by a given angle.
void rotate(int left, int top, int right, int bottom) {
  float rad, x1, x2, x3, x4, y1, y2, y3, y4;
  int deg;
  printf("\nEnter the angle to rotate :");
  scanf("%d", &deg);
  rad = deg * (3.14 / 180);

  x1 = left * cos(rad) - bottom * sin(rad);
  y1 = left * sin(rad) + bottom * cos(rad);
  x2 = right * cos(rad) - bottom * sin(rad);
  y2 = right * sin(rad) + bottom * cos(rad);
  x3 = left * cos(rad) - top * sin(rad);
  y3 = left * sin(rad) + top * cos(rad);
  x4 = right * cos(rad) - top * sin(rad);
  y4 = right * sin(rad) + top * cos(rad);

  line(fabs(x1), fabs(y1), fabs(x2), fabs(y2));
  line(fabs(x1), fabs(y1), fabs(x3), fabs(y3));

  line(fabs(x3), fabs(y3), fabs(x4), fabs(y4));
  line(fabs(x2), fabs(y2), fabs(x4), fabs(y4));
}

// Scales a rectangle by a given factor in the x and y directions.
void scaling(int x1, int y1, int x2, int y2, float sx, float sy) {
  // Translate the rectangle to the origin.

  int nx,ny;
  //float nx, ny;
  translate(x1,y1,x2,y2,0,0);
  // Scale the rectangle.
  nx =(int) ((x2 - x1) * sx);
  ny = (int)((y2 - y1) * sy);
  rectangle(0, 0, nx, ny);
  //nnx=(int)(nx);
  //nny=(int)(ny);
  // Translate the rectangle back to its original position.
  translate(0, 0, nx, ny, x1, y1);
}

int main() {

  float radians, sx, sy;
  int gd = DETECT, gm, choice, x1, x2, y1, y2, xt, yt, angle;

  // Initialize the graphics system.
  initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");

  // Prompt the user to enter the coordinates of the rectangle.
  printf("Enter cords of diagonal: ");
  scanf("%d%d%d%d", &x1, &y1, &x2, &y2);

  // Draw the rectangle.
  rectangle(x1, y1, x2, y2);

  // Prompt the user to enter a choice.
  printf("\nEnter 1 for Translation\nEnter 2 for Rotation\nEnter 3 for Scaling\nEnter -> ");
  scanf("%d", &choice);

  switch (choice) {
  case 1:
    // Prompt the user to enter the coordinates to translate to.
    printf("\nEnter cords to be translated at: ");
    scanf("%d%d", &xt, &yt);
    translate(x1, y1, x2, y2, xt, yt);
    break;
  case 2:
    // Rotate the rectangle.
    rotate(x1, y1, x2, y2);
    break;
  case 3:
    // Prompt the user to enter the scaling factors.
     printf("\nEnter how much you want to scale along x and y axis: ");
   scanf("%f%f", &sx, &sy);
   scaling(x1, y1, x2, y2, sx, sy);
   break;
  default:
   printf("\nWrong input");
 }

 // Display the transformed rectangle.
 getch();
 closegraph();

 return 0;
}
