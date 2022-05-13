#include<iostream.h>
#include<conio.h>
#include<math.h>
#include<stdlib.h>
#include<dos.h>
#include<graphics.h>
void bresen(int x1, int y1,int x2, int y2);
int sign (float arg);
void main()
{
int gd = DETECT, gm;
int x1,y1,x2,y2;
initgraph (&gd,&gm,"c:\\tc\\bgi");
cleardevice();
cout<<" Bresenhams line drawing ";
cout<< "\n enter the starting point's co-ordinates for line\n ";
cin>>x1>>y1;
cout<<"\n enter the ending points co-ordinates\n";
cin>>x2>>y2;
bresen(x1,y1,x2,y2);
cout<< "\n Thank you";
getch();
closegraph();
}
void bresen(int x1,int y1, int x2,int y2)
{ int s1,s2,exchange,y,x,i;
float dx, dy,g,temp;
dx = abs(x2-x1);
dy = abs(y2-y1);
x = x1;
y = y1;
s1 = sign(x2-x1);
s2 = sign(y2-y1); /* interchange dx & dy depending on the slope of the line */
if(abs(dy)>abs(dx))
{
temp = dx;
dx = dy;
dy = temp;
exchange = 1;
}
else
{
exchange = 0;
}
g = 2 * dy-dx;
i= 1;

	setcolor(10);
	line(0,240,639,240);
	line(320,0,320,479);
	outtextxy(295,243,"0,0");
	setcolor(WHITE);

while(i<=dx)
{
	//putpixel(x,y,WHITE);
	putpixel(320+x,240-y,15);
	if(g>=0)
	{
		if(exchange ==1)
			x = x + s1;
		else
			y = y + s2;
		g=g-2*dx;
		g=g+ 2 * dy;
	}
	else{
		if(exchange==1)
			y = y + s2;
		else
			x = x + s1;
		g=g+ 2 * dy;
	}
		i++;
	}
}
int sign(float arg)
{
if (arg<0)
{
return-1;
}
else if(arg==0)
{
return 0;
}
else
{
return 1;
}
}