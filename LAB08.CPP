#include<stdio.h>
#include<process.h>
#include<conio.h>
#include<iostream.h>
#include<dos.h>
#include<graphics.h>
float arr[4][2];
int cnt;
void line_draw(float x,float y)
{
line(arr[0][0],arr[0][1],x,y);
arr[0][0]=x;
arr[0][1]=y;
}
void bezier(float xb,float yb,float xc,float yc,float xd,float yd, int cnt)
{
float xp,yp,xq,yq,xr,yr,xs,ys,xu,yu,xt,yt;
if(cnt!=0)
{ xp=(arr[0][0]+xb)/2;
yp=(arr[0][1]+yb)/2;
putpixel(xp,yp, 4);
xq=(xb+xc)/2;
yq=(yb+yc)/2;
putpixel(xp,yp, 4);
xr=(xc+xd)/2;
yr=(yc+yd)/2;
putpixel(xp,yp,4);
xs=(xp+xq)/2;
ys=(yp+yq)/2;
putpixel(xp,yp,4);
xu=(xq+xr)/2;
yu=(yq+yr)/2;
putpixel(xp,yp,4);
xt=(xs+xu)/2;
yt=(ys+yu)/2;
putpixel(xp,yp,4);
cnt-- ;
//delay(10);
bezier(xp,yp,xs,ys,xt,yt,cnt);
//delay(10);
bezier(xu,yu,xr,yr,xd,yd,cnt);
//delay(10);
}
else
{
line_draw(xb,yb);
line_draw(xc,yc);
line_draw(xd,yd);
}
}
void main()
{
clrscr();
int gd=DETECT,gm, P = 8,j;
initgraph(&gd,&gm,"c:\\tc\\bgi");
// cout<<"Enter the 0 point:- ";
// cin>>arr[0][0]>>arr[0][1];
// cout<<"Enter the 1 point:- ";
// cin>>arr[1][0]>>arr[1][1];
// cout<<"Enter the 2 point:- ";
// cin>>arr[2][0]>>arr[2][1];
// cout<<"Enter the 3 point:- ";
// cin>>arr[3][0]>>arr[3][1];
arr[0][0]=50;
arr[0][1]=50;
arr[1][0]=250;
arr[1][1]=50;
arr[2][0]=250;
arr[2][1]=250;
arr[3][0]=50;
arr[3][1]=250;
cleardevice();
for(j=0;j<3;j++)
line(arr[j][0],arr[j][1],arr[j+1][0],arr[j+1][1]);
bezier(arr[1][0],arr[1][1],arr[2][0],arr[2][1],arr[3][0],arr[3][1],P);
getch();
cleardevice();
closegraph();
}