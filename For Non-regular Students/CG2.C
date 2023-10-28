#include<stdio.h>
#include<conio.h>
#include<graphics.h>
void main()
{
	int gd=DETECT,gm,i,x,y,xc,yc,r,p;
	clrscr();
	initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");
	printf("Enter center coordinates: ");
	scanf("%d %d",&xc,&yc);
	printf("Enter radius: ");
	scanf("%d",&r);
	x=0;
	y=r;
	p=1-r;
	putpixel(0,r,RED);
	putpixel(0,-1*r,RED);
	putpixel(-1*r,0,RED);
	putpixel(r,0,RED);
	while(x<y)
	{
		delay(100);
		if(p<0)
		{
			x++;
			p=p+(2*x)+1;
			putpixel(  x+xc   ,  y+yc   ,RED);
			putpixel(  x+xc   ,(-1*y)+yc,RED);
			putpixel((-1*x)+xc,  y+yc   ,RED);
			putpixel((-1*x)+xc,(-1*y)+yc,RED);
			putpixel(  y+xc   ,  x+yc   ,RED);
			putpixel(  y+xc   ,(-1*x)+yc,RED);
			putpixel((-1*y)+xc,  x+yc   ,RED);
			putpixel((-1*y)+xc,(-1*x)+yc,RED);
		}
		else
		{
			x++;
			y--;
			p=(2*x)+1-(2*y);
			putpixel(  x+xc   ,  y+yc   ,RED);
			putpixel(  x+xc   ,(-1*y)+yc,RED);
			putpixel((-1*x)+xc,  y+yc   ,RED);
			putpixel((-1*x)+xc,(-1*y)+yc,RED);
			putpixel(  y+xc   ,  x+yc   ,RED);
			putpixel(  y+xc   ,(-1*x)+yc,RED);
			putpixel((-1*y)+xc,  x+yc   ,RED);
			putpixel((-1*y)+xc,(-1*x)+yc,RED);
		}
	}
	getch();
}