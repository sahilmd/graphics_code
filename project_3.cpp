/*Using Mid-Point circle generating algorithm plot two circular arcs with 
central angle 135 degree to 90 degree*/

#include<stdio.h>
#include<graphics.h>
#include<math.h>

double toDegrees(double radians) {
    return radians * (180.0 / M_PI);
}



void drawCirclePoints(int
centerX, int centerY, int x, int y, int startAngle, int endAngle) {

        // Calculate the angle the current point makes with the circle center
        int angle = (int) toDegrees(atan2(y, x));

        // draw the circle points as long as they lie in the range specified
        if (x < y) {
            // draw point in range 0 to 45 degrees
            if (90 - angle >= startAngle && 90 - angle <= endAngle) {
                putpixel(centerX - y, centerY - x,7);
            }

            // draw point in range 45 to 90 degrees
            if (angle >= startAngle && angle <= endAngle) {
                putpixel( centerX - x, centerY - y,7);
            }

            // draw point in range 90 to 135 degrees
            if (180 - angle >= startAngle && 180 - angle <= endAngle) {
                putpixel(centerX + x, centerY - y,7);
            }

            // draw point in range 135 to 180 degrees
            if (angle + 90 >= startAngle && angle + 90 <= endAngle) {
                putpixel(centerX + y, centerY - x,7);
            }

            // draw point in range 180 to 225 degrees
            if (270 - angle >= startAngle && 270 - angle <= endAngle) {
                putpixel(centerX + y, centerY + x,7);
            }

            // draw point in range 225 to 270 degrees
            if (angle + 180 >= startAngle && angle + 180 <= endAngle) {
                putpixel(centerX + x, centerY + y,7);
            }

            // draw point in range 270 to 315 degrees
            if (360 - angle >= startAngle && 360 - angle <= endAngle) {
                putpixel(centerX - x, centerY + y,7);
            }

            // draw point in range 315 to 360 degrees
            if (angle + 270 >= startAngle && angle + 270 <= endAngle) {
                putpixel(centerX - y, centerY + x,7);
            }
        }
    
}


 
void drawcircle(int x0, int y0, int r,int sa,int ea)
{
    int x = 0;
    int y = r;
    int p=1-r;
    int cx=x0;
    int cy=y0;
 
    while (x<y)
    {
	//putpixel(x0 + x, y0 + y, 7);
	//putpixel(x0 + y, y0 + x, 7);
	//putpixel(x0 - y, y0 + x, 7);
	putpixel(x0 - x, y0 + y, 7);
	//putpixel(x0 - x, y0 - y, 7);
	//putpixel(x0 - y, y0 - x, 7);
	putpixel(x0 + y, y0 - x, 7);
//	putpixel(x0 + x, y0 - y, 7);
 	
 	x++;
	if (p<0)
	{
	   p+=(2*x)+1;
	}
 	else
	{
	    p+=(2*(x-y))+1;
	    y--;
	}
	
	drawCirclePoints(cx, cy, x, y, sa, ea);
    }
}




 
int main()
{
	int error, x, y, r,sa=135,ea=90;
 
	printf("Enter radius of circle: ");
	scanf("%d",&r);
 
	printf("Enter co-ordinates of center(x and y): ");
	scanf("%d %d",&x,&y);
	
	initwindow(680,480);
	drawcircle(x, y, r,sa,ea);
 	getch();
	return 0;
}
