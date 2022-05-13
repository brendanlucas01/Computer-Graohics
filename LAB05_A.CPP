#include <iostream.h>
#include<conio.h>
#include<dos.h>
#include<process.h>
#include <graphics.h>
#include<math.h>
#include<stdlib.h>
void boundary(int x, int y, int new_col)
{
if (getpixel(x, y) != new_col && getpixel(x, y) !=WHITE)
{
// put new pixel with new color
putpixel(x, y, new_col);
//delay(5);
boundary(x + 1, y, new_col);
boundary(x - 1, y, new_col);
boundary(x, y + 1, new_col);
boundary(x, y - 1, new_col);
boundary(x+1, y + 1, new_col);
boundary(x-1, y + 1, new_col);
boundary(x+1, y - 1, new_col);
boundary(x-1, y - 1, new_col);
}
}
int main()
{
int gd= DETECT,gm;
initgraph(&gd, &gm, "c:\\tc\\bgi");
cleardevice();
int top, left, bottom, right,x,y,newcolor,oldcolor;
cout<<"\nBOUNDARY FILL ALGORITHM\n";
// cout<<"Enter the topleft coordinate: ";
// cin>>left;
left=200;
top = left;
// cout<<"Enter the bottomright coordinate: ";
// cin>>right;
right=250;
bottom = right;
rectangle(left, top, right, bottom);
//delay(500);
x = left+1;
y = left+1;
// cout<<"Enter the color Number coordinate: ";
// cin>>newcolor;
newcolor=4;
oldcolor = 0;
boundary(x, y, newcolor);
getch();
cleardevice();
closegraph();
return 0;
}