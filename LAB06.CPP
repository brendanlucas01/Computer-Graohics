#include <iostream.h>
#include <conio.h>
#include <stdlib.h>
#include <math.h>
#include<graphics.h>
//using namespace std;
class transformation
{
public:
int edges;
void menu(int a[20][3]);
void input(int a[20][3]);
void printer(int a[][3],int row);
void multiply(int a[20][3],int b[3][3]);
void multiplyfloat(int a[20][3],float b[3][3]);
void scailing(int a[20][3]);
void translation(int a[20][3]);
void sheer(int a[20][3]);
void rotation(int a[20][3]);
void reflect(int a[20][3]);
void disp(int a[][3]);
};
void transformation::input(int a[20][3])
{
int i;
do
{
cout<<"Enter the Number of vertices:- \n";
cin>>edges;
if(edges<=1)
{
cout<<"Figure Not possible. Try Again";
}
}while(edges<=0);
for(i=0;i<edges;i++)
{
cout<<"\nEnter the coordinates of "<<i+1<<" vertex :- ";
cin>>a[i][0];
cin>>a[i][1];
a[i][2]=1;
}
// printer(res, edges);
disp(a);
}
void transformation ::printer(int a[][3],int row)
{
int i;
for(i=0;i<row;i++)
{
cout<<a[i][0]<<" "<<a[i][1]<<" "<<a[i][2]<<"\n";
}
}
void transformation :: multiply(int a[20][3],int b[3][3])
{
int res[20][3],i,j;
for(i=0;i<edges;i++)
{
res[i][0]=(int)(a[i][0]*b[0][0]+a[i][1]*b[1][0]+a[i][2]*b[2][0]);
res[i][1]=(int)(a[i][0]*b[0][1]+a[i][1]*b[1][1]+a[i][2]*b[2][1]);
res[i][2]=(int)(a[i][0]*b[0][2]+a[i][1]*b[1][2]+a[i][2]*b[2][2]);
}
// printer(res, edges);
disp(res);
for(i=0;i<edges;i++)
{
for(j=0;j<2;j++)
{
a[i][j]=res[i][j];
}
}
}
void transformation :: multiplyfloat(int a[20][3],float b[3][3])
{
int res[20][3],i,j;
for(i=0;i<edges;i++)
{
res[i][0]=(int)(a[i][0]*b[0][0]+a[i][1]*b[1][0]+a[i][2]*b[2][0]);
res[i][1]=(int)(a[i][0]*b[0][1]+a[i][1]*b[1][1]+a[i][2]*b[2][1]);
res[i][2]=(int)(a[i][0]*b[0][2]+a[i][1]*b[1][2]+a[i][2]*b[2][2]);
}
// printer(res, edges);
disp(res);
for(i=0;i<edges;i++)
{
for(j=0;j<2;j++)
{
a[i][j]=res[i][j];
}
}
}
void transformation :: disp(int a[][3])
{
int i;
clrscr();
cleardevice();
setcolor(10);
line(0,240,639,240);
line(320,0,320,479);
outtextxy(295,243,"0,0");
setcolor(WHITE);
for(i=0;i<edges-1;i++)
{
line((a[i][0]+320),(240-a[i][1]),(a[i+1][0]+320),(240-a[i+1][1]));
}
line((a[0][0]+320),(240-a[0][1]),(a[i][0]+320),(240-a[i][1]));
getch();
}
void transformation :: scailing(int a[20][3])
{
int i;
float scal[3][3];
for(i=0;i<3;i++)
{
scal[i][0]=scal[i][1]=scal[i][2]=0;
}
scal[2][2]=1;
cout<<"Enter the value of x-scaling :- ";
cin>>scal[0][0];
cout<<"Enter the value of y-scaling :- ";
cin>>scal[1][1];
//printer(scal,3);
multiplyfloat(a, scal);
}
void transformation :: translation(int a[20][3])
{
int i,trans[3][3];
for(i=0;i<3;i++)
{
trans[i][0]=trans[i][1]=trans[i][2]=0;
}
trans[0][0]=trans[1][1]=trans[2][2]=1;
cout<<"Enter the value of translation in x direction :- ";
cin>>trans[2][0];
cout<<"Enter the value of translation in y direction :- ";
cin>>trans[2][1];
//printer(trans,3);
multiply(a, trans);
}
void transformation :: sheer(int a[20][3])
{
int i;
float shr[3][3];
for(i=0;i<3;i++)
{
shr[i][0]=shr[i][1]=shr[i][2]=0;
}
shr[0][0]=shr[1][1]=shr[2][2]=1;
cout<<"Enter the value of x-sheer :- ";
cin>>shr[1][0];
cout<<"Enter the value of y-sheer :- ";
cin>>shr[0][1];
//printer(shr,3);
multiplyfloat(a, shr);
}
void transformation :: rotation(int a[20][3])
{
int i;
float ang,rot[3][3];
cout<<"Enter the Angle of rotation :- ";
cin>>ang;
ang=ang*3.14/180;
for(i=0;i<3;i++)
{
rot[i][0]=rot[i][1]=rot[i][2]=0;
}
rot[0][0]=rot[1][1]=cos(ang);
rot[2][2]=1;
rot[0][1]=rot[1][0]=sin(ang);
cout<<"Press 1 for clockwise\n2 for anticlockwise\n ";
cin>>i;
if(i==1)
{
rot[0][1]=-rot[0][1];
}
else
{
rot[1][0]=-rot[1][0];
}
//printer(shr,3);
multiplyfloat(a, rot);
}
void transformation :: reflect(int a[20][3])
{
int i,ref[3][3];
for(i=0;i<3;i++)
{
ref[i][0]=ref[i][1]=ref[i][2]=0;
}
ref[0][0]=ref[1][1]=ref[2][2]=1;
cout<<"Enter the type of reflection:\n1 for reflection about X-axis\n2 for reflection about Y-axis\n3 for reflection about Origin\n4 for reflection about y=x\n";
do
{
cin>>i;
if(i>4||i<1)
{
cout<<"Invalid option, Try again\n";
}
}while(i<1||i>4);
if(i==1)
{
ref[1][1]=-ref[1][1];
}
else if(i==2)
{
ref[0][0]=-ref[0][0];
}
else if(i==3)
{
ref[0][0]=-ref[0][0];
ref[1][1]=-ref[1][1];
}
else if(i==4)
{
ref[0][0]=0;
ref[1][1]=0;
ref[0][1]=1;
ref[1][0]=1;
}
//printer(shr,3);
multiply(a, ref);
}
void transformation :: menu(int a[20][3])
{
int i;
cout<<"Enter Your Choice of transformation\n1 for scailing\n2 for translation\n3 for sheer\n4 for rotation\n5 for reflection\n";
cin>>i;
switch(i)
{
case 1:{scailing(a);break;}
case 2:{translation(a);break;}
case 3:{sheer(a);break;}
case 4:{rotation(a);break;}
case 5:{reflect(a);break;}
default:{cout<<"Invalid option, Try again\n";break;}
}
}
int main()
{
int gd=DETECT,gm;
initgraph(&gd,&gm,"c:\\tc\\bgi");
int a[20][3];
char desi;
clrscr();
cleardevice();
transformation tr;
tr.input(a);
do
{
tr.menu(a);
cout<<"Do you want to continue ?, press Y:- ";
cin>>desi;
}while(desi=='y'||desi=='Y');
cout<<"Thank You! End of program";
getch();
closegraph();
return 0;
}