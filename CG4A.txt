#include<stdio.h>
#include<conio.h>
#include<graphics.h>
void main()
{
	int gd=DETECT,gm;
	int x,y,r;
	initgraph(&gd,&gm,"c:\\TURBOC3\\BGI");
	printf("enter the co-ordinates:-");
	scanf("%d %d",&x,&y);
	printf("enter the radius of the circle:-");
	scanf("%d",&r);

	setcolor(BLUE);
	circle(x,y,r);
	setfillstyle(SOLID_FILL,WHITE);
	floodfill(x,y,BLUE);

	getch();
	closegraph();
}