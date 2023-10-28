#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<graphics.h>

void main()
{
	int gd=DETECT,gm,i,x1,y1,x2,y2;
	float x,y,dx,dy,xi,yi,steps;
	clrscr();
	printf("\033[0;37m");
	initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");
	printf("Enter points: ");
	setbkcolor(WHITE);
	scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
	dx=x2-x1;
	dy=y2-y1;
	if(dx>dy)
	steps=dx;
	else
	steps=dy;
	xi=dx/(float)steps;
	yi=dy/(float)steps;
	x=x1;
	y=y1;
	putpixel(x,y,RED);
	i=0;
	

while(i<steps)
	{
		x=x+xi;
		y=y-yi;
		putpixel(x,y,RED);
		i++;
	}
	getch();
	closegraph();
}