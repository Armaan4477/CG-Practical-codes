#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<graphics.h>

void main()
{
	int gd=DETECT,gm,i,x1,y1,x2,y2;
	float x,y,dx,dy,xi,yi,p,m;
	clrscr();
	printf("\033[0;37m");
	initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");
	printf("Enter points: ");
	setbkcolor(WHITE);
	scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
	x=x1;
	y=y1;
	putpixel(x,y,RED);
	dx=x2-x1;
	dy=y2-y1;
	m=dy/dx;
	if(m<1)
	{       p=(2*dy)-dx;
		for(i=1;i<=dx;i++)
		{
			if(p<0)
			{
				putpixel(x++,y,RED);
				p=p+(2*dy);
			}
			else
			{
			putpixel(x++,y--,RED);
			p=p+(2*dy)-(2*dx);
			}
		}
	}
	else
	{       p=(2*dx)-dy;
		for(i=1;i<=dy;i++)
		{
			if(p<0)
			{
				putpixel(x,y--,RED);
				p=p+(2*dx);
			}
			else
			{
				putpixel(x++,y--,RED);
				p=p+(2*dx)-(2*dy);
			}
		}
	}
	getch();
	closegraph();
}