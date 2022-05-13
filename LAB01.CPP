#include <graphics.h>
#include <iostream.h>
#include<conio.h>
#include <math.h>
#include <dos.h>

void main( )

{
	float x,y,x1,y1,x2,y2,dx,dy,step,t;
	int i,gd=DETECT,gm;
	initgraph(&gd,&gm,"c:\\tc\\bgi");
	cout<<"Enter the value of x1 and y1 : ";
	cin>>x1>>y1;
	cout<<"Enter the value of x2 and y2: ";
	cin>>x2>>y2;
	if(y2<y1)
	{
	  t=y2;
	  y2=y1;
	  y1=t;
	  t=x2;
	  x2=x1;
	  x1=t;
	}
	dx=x2-x1;
	dy=y2-y1;
	if(abs(dx)>=abs(dy))
		step=abs(dx);
	else
		step=abs(dy);
	dx=dx/step;
	dy=dy/step;
	x=x1;
	y=y1;
	i=1;

	setcolor(10);
	line(0,240,639,240);
	line(320,0,320,479);
	outtextxy(295,243,"0,0");
	setcolor(WHITE);

	while(i<=step)
	{
		putpixel(320+x,240-y,15);
		//putpixel(x,y,15);
		x=x+dx;
		y=y+dy;
		i=i+1;
		delay(100);
	}
	getch();
	closegraph();

}
