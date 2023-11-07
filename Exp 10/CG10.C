#include <graphics.h>
#include <dos.h>
#include <conio.h>
#include <stdio.h>
void main()
{
   int i, j = 0, gd = DETECT, gm;

   initgraph(&gd,&gm,"c:\\turboc3\\bgi");
   printf("Press any ket to view the moving car");
   //settextstyle(DEFAULT_FONT,HORIZ_DIR,2);
   //outtextxy(25,240,"Press any key to view the moving car");

   getch();
   //setviewport(0,0,639,440,1);

   for (i = -150; i <= 700; i = i + 10, j++)
   {
      rectangle(50+i,275,150+i,400);
      rectangle(150+i,350,200+i,400);
      circle(75+i,410,10);
      circle(175+i,410,10);
      setcolor(j);
      delay(100);

      if (i == 720)
	 break;

      clearviewport();
   }

   getch();
   closegraph();
}