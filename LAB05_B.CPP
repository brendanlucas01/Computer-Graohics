#include <iostream.h>
#include<conio.h>
#include<dos.h>
#include<process.h>
#include <graphics.h>
#include<math.h>
#include<stdlib.h>
void flood(int x, int y, int new_col, int old_col)
{
if (getpixel(x, y) == old_col)
{
// put new pixel with new color
putpixel(x, y, new_col);
//delay(5);
flood(x + 1, y, new_col, old_col);
flood(x - 1, y, new_col, old_col);
flood(x, y + 1, new_col, old_col);
flood(x+1, y + 1, new_col, old_col);
flood(x-1, y + 1, new_col, old_col);
flood(x, y - 1, new_col, old_col);
flood(x+1, y - 1, new_col, old_col);
flood(x-1, y - 1, new_col, old_col);
}
}
int main()
{
int gd= DETECT,gm;
initgraph(&gd, &gm, "c:\\tc\\bgi");
cleardevice();
int top, left, bottom, right,x,y,newcolor,oldcolor;
cout<<"\nFLOOD FILL ALGORITHM\n";
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
newcolor=10;
oldcolor = 0;
flood(x, y, newcolor, oldcolor);
getch();
cleardevice();
closegraph();
return 0;
}