#include<stdio.h>
#include<graphics.h>
#include<math.h>

int xc=150,yc=200,r=60;
int x[15],y[15];

int arr[] = {150,200, 130, 400,  
                170, 400,  150, 200}; 

int main()
{
	double angle=0,theta;
	int sp,speed;
	int dir;
	int i,a;
	
	printf("enter speed of the windmill (MAX SPEED = 200): ");
	scanf("%d",&sp);
	if(sp<0)
		speed=0;
	else if(sp>200)
		speed=200;
	else
		speed=1500/sp;
	printf("\n clockwise: press +1\n anti-clockwise: press -1\n");
	scanf("%d",&dir);
	int gd=DETECT,gm;
	initgraph(&gd,&gm,"bgi");
	
	while(!kbhit())
	{
	
		cleardevice();
		setcolor(RED);
		setfillstyle(XHATCH_FILL, RED); 
		fillpoly(4, arr);  
		setcolor(YELLOW);
		setfillstyle(SOLID_FILL,YELLOW); 
		circle(xc,yc,4); 
		floodfill(xc,yc,YELLOW); 
		for(i=0;i<4;i++)
		{
			theta=M_PI*angle/180;
			x[i]=xc+r*cos(theta);
			y[i]=yc+r*sin(theta);
			angle+=90;
			line(xc,yc,x[i],y[i]);
		
		}
		if(dir==1)		
		angle+=5;
		else
		angle-=5;
		for(i=0;i<4;i++)
		{
			theta=M_PI*angle/180;
			x[i]=xc+r*cos(theta);
			y[i]=yc+r*sin(theta);
			angle+=90;
			line(xc,yc,x[i],y[i]);
		}
		angle+=dir*10;
		delay(speed);
	}
	
	getch();
	closegraph();
}


