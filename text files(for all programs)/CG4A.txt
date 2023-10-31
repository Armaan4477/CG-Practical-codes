#include<stdio.h>
#include<conio.h>
#include<graphics.h>
void floodf(int x,int y,int old,int newc)
{
int current;
current=getpixel(x,y);
if(current==old)
{
putpixel(x,y,newc);
floodf(x+1,y,old,newc);
floodf(x-1,y,old,newc);
floodf(x,y+1,old,newc);
floodf(x,y-1,old,newc);
}
}
void main()
{
	int gd=DETECT,gm;
	int x,y,r;
	initgraph(&gd,&gm,"c:\\TURBOC3\\BGI");
	printf("enter the co-ordinates:-");
	scanf("%d %d",&x,&y);
	printf("enter the radius of the circle:-");
	scanf("%d",&r);
	circle(x,y,r);
	floodf(x,y,0,15);


	getch();
	closegraph();
}