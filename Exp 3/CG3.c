#include<stdio.h>
#include<conio.h>
#include<graphics.h>
void main(){
      long  x,y,xc,yc,i=1;
      long rx2,ry2, fx,fy, p1,rx,ry,x1,y1;
      int gd=DETECT,gm;
      clrscr();

    initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");//initializing graph
    printf("\033[0;37m");//changing text color
    setbkcolor(WHITE);//changing background color
    printf("\n\n Enter coordinate xc and yc = ");//taking center coordinates
    scanf("%ld%ld",&xc,&yc);
    printf("\n Now enter constants rx and ry = ");//taking major and minor axis values
    scanf("%ld%ld",&rx,&ry);
    x=0;
    y=ry;
    rx2=rx*rx;
    ry2=ry*ry;
    fx=2*ry2*x;
    fy=2*rx2*y;
  p1=ry2-(rx2*ry)+(rx2*0.25);//initializing decision parameter for region 1
  do
   {
  putpixel(xc+x,yc+y,i);
  putpixel(xc-x,yc-y,i);
  putpixel(xc+x,yc-y,i);
  putpixel(xc-x,yc+y,i);//plotting pixels for all 4 quadrants
    /*if(i==100)//used for randomizing color
    i=1;
    else
    i++;*/
   if(p1<0)//comparing decision parameter
    {
  p1=p1+fx+ry2;//finding out successive decision parameter
    }
   else
  {
  
y=y-1;
  p1=p1+fx+-fy+ry2;//finding out successive decision parameter
  fy=fy-(2*rx2);
  }
  x=x+1;
  fx=fx+(2*ry2);
  delay(100);

   }
   while(fx<fy);//continuing till condition is false
   x1=(x+0.5)*(x+0.5);
   y1=(y-1)*(y-1);
   p1=ry2*x1+rx2*y1-(rx2*ry2);//initializing decision parameter for region 2
   do
   {
  putpixel(xc+x,yc+y,i);
  putpixel(xc-x,yc-y,i);
  putpixel(xc+x,yc-y,i);
  putpixel(xc-x,yc+y,i);//plotting pixels for all 4 quadrants
   /*if(i==100)//used to randomize color
    i=1;
    else
    i++;*/
   if(p1>=0)//comparing decision parameter
  p1=p1-fy+rx2;//finding out successive decision parameter
   else


  {
  x=x+1;
  p1=p1+fx-fy+rx2;//finding out successive decision parameter
  fx=fx+(2*ry2);
  }
   y=y-1;
   fy=fy-(2*rx2);
   delay(100);
   }
   while(y>0);//continue until axis reached
   getch();
   closegraph();//closing graph
}
