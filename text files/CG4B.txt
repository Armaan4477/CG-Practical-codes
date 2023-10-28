#include<stdio.h>
#include<conio.h>
#include<graphics.h>
void boundaryfill(int x,int y,int f_color,int b_color)
{
	if(getpixel(x,y)!=b_color&&getpixel(x,y)!=f_color)
	{
		putpixel(x,y,f_color);
		boundaryfill(x+1,y,f_color,b_color);
		boundaryfill(x,y+1,f_color,b_color);
		boundaryfill(x-1,y,f_color,b_color);
		boundaryfill(x,y-1,f_color,b_color);
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
	boundaryfill(x,y,RED,WHITE);


	getch();
	closegraph();
}