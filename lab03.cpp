#include<iostream.h>
#include<conio.h>
#include<math.h>
#include<stdlib.h>
#include<graphics.h>
#include<dos.h>
void circ_midpt(int x,int y,int rad);
void display(int,int, int, int);
void main()
{
int gd = DETECT, gm, x,y,r;
initgraph(&gd,&gm,"c:\\tc\\bgi");
cleardevice();
cout<<" Midpoint circle generation algorithm ";
cout<<"\n enter the center co-ordinates for the circle\n";
cin>>x>>y;
cout<<"\n enter the radius of the circle\n";
cin>>r;
circ_midpt(x,y,r);
getch();
closegraph();
}
void circ_midpt(int x,int y,int rad)
{
	int x1,y1;
	float dp; //initialising the descision parameter. /initialisng the X,Y cordinates.
	x1 = 0;
	y1 = rad;
	dp = 1-rad;

	setcolor(10);
	line(0,240,639,240);
	line(320,0,320,479);
	outtextxy(295,243,"0,0");
	setcolor(WHITE);

	while(x1<=y1)
	{
		if(dp<=0)
		{
			x1++;
			dp += (2 * x1) + 1;
		}
		else
		{
			x1++;
			y1--;
			dp += 2* (x1-y1)+1;
		}
		display(x1,y1,x,y);
	}
}
void display (int x1,int y1, int x,int y)
{
putpixel(320+(x1+x),240-(y1+y),WHITE);
putpixel(320+(x1+x),240-(y-y1),WHITE);
putpixel(320+(x-x1),240-(y1+y),WHITE);
putpixel(320+(x-x1),240-(y-y1),WHITE);
putpixel(320+(x+y1),240-(y+x1),WHITE);
putpixel(320+(x+y1),240-(y-x1),WHITE);
putpixel(320+(x-y1),240-(y+x1),WHITE);
putpixel(320+(x-y1),240-(y-x1),WHITE);
}