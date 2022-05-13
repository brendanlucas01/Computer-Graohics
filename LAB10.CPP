#include<math.h>
#include<conio.h>
#include <graphics.h>

#define PI 3.141592
void branch(float x,float y,float len,float theta)
{
	float x2 = x + len*cos(theta),y2 = y + len*sin(theta); // FINDING ENDPOINT

	putpixel(x,y,WHITE);
	putpixel(x2,y2,WHITE);

    float midX = x + len/1.8*cos(theta),midY = y + len/1.8*sin(theta);

     if(len >20) // STOPPING CONDITION
	 {
		 branch(midX,midY,len/2,theta + PI/3); // RECURSIVE CALLS
		 branch(midX,midY,len/2,theta - PI/3);
		 branch(midX,midY,len/2,theta + PI/6);
		 branch(midX,midY,len/2,theta - PI/6);
	 }
}

int main()
{
	int gd = DETECT, gm;
	initgraph(&gd, &gm, "c:\\tc\\bgi");
	branch(300,75,300,PI/2); // THE MAIN BARK OF TREE
	getch();
	closegraph();
	return 0;
}