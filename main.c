#include <stdlib.h>
#include <graphics.h>

void DrawFractal(int order, float length, float x, float y)
{
    line(x-length/2,y,x+length/2,y);
    line(x-length/2,y-length/2,x-length/2,y+length/2);
    line(x+length/2,y-length/2,x+length/2,y+length/2);
 
    if( order > 1 )
    {
        DrawFractal(order-1,length/2,x-length/2,y-length/2);
        DrawFractal(order-1,length/2,x+length/2,y-length/2);
        DrawFractal(order-1,length/2,x-length/2,y+length/2);
        DrawFractal(order-1,length/2,x+length/2,y+length/2);
    }
}
 
int main(int argc, char** argv)
{

    int gdriver = DETECT, gmode;
    
    initgraph(&gdriver, &gmode, NULL);

    int SIDE = 500;
 
    for (int order = 1; order <= 10; order++)
    {
        cleardevice();
 
        DrawFractal(order,(SIDE-100)/2,SIDE/2,SIDE/2);
        outtextxy(150, 30, "Press any key...");
        getch();
    }
 
    return 0;
}