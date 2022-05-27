#include <string.h>
#include <stdlib.h>
#include <graphics.h>
#include <X11/Xlib.h>
#include <math.h>

#include "commands.h"

// Global variables that will be used in multiple functions
float x, y;
float pi = 3.141592;
int angle;

// Calculates new angle + given alpha
void Plus(int alpha)
{
    angle += alpha;
    if (angle >= 360 )
        angle = angle - 360;
}

// Calculates new angle - given alpha
void Minus(int alpha)
{
    angle -= alpha;
    if (angle < 0 )
        angle = angle + 360;
}

// Transforms angle from degrees to radians and
// draws a new line of length = length
void DrawLine(float length)
{
    float new_x,new_y;
    float angle_radians = 2 * pi * angle / 360;
    new_x = x + length * cos(angle_radians);
    new_y = y - length * sin(angle_radians);
 
    line(x, y, new_x, new_y);
 
    x = new_x;
    y = new_y;
}

void DrawFractal1(int order, float length, float x, float y)
{
    // Draws the first H shape
    line(x - length / 2, y, x + length / 2, y);
    line(x - length / 2, y - length / 2, x - length / 2, y + length / 2);
    line(x + length / 2, y - length / 2, x + length / 2, y + length / 2);
    
    // Draws a new H in each corner of the original shape
    if( order > 1 ) {
        DrawFractal1(order - 1, length / 2, x - length / 2, y - length / 2);
        DrawFractal1(order - 1, length / 2, x + length / 2, y - length / 2);
        DrawFractal1(order - 1, length / 2, x - length / 2, y + length / 2);
        DrawFractal1(order - 1, length / 2, x + length / 2, y + length / 2);
    }
}

// Draws a H-Fractal
void OptionOne(int order)
{
    int SIDE = 500;
 
    for (int i= 1; i <= order; i++) {
        cleardevice();
 
        DrawFractal1(i, (SIDE - 100) / 2, SIDE / 2, SIDE / 2);
        outtextxy(150, 30, "Press any key...");
        getch();
    }
}

void DrawFractal2(int order, float length, float angle, float x, float y)
{
    float added_angle = 25;
    float length_ratio = 0.75;
    float new_x, new_y;
    float angle_radians = 2 * pi * angle / 360;
    new_x = x + length * cos(angle_radians);
    new_y = y - length * sin(angle_radians);
    
    // Draws tree line when order = 1
    line(x, y, new_x, new_y);
 
    // Recursive calls for each new branch
    if (order > 1 ) {
        DrawFractal2(order - 1, length * length_ratio, angle + added_angle, new_x, new_y );
        DrawFractal2(order - 1, length * length_ratio, angle - added_angle, new_x, new_y );
    }
}

// Draws a Fractal Tree
void OptionTwo(int order)
{
    int SIDE = 600;

    for (int i = 1; i <= order; i++) {
        cleardevice();

        DrawFractal2(i, 130, 90, SIDE / 2, SIDE - 50);
        outtextxy(150, 30, "Press any key...");
        getch();
    }
}

void DrawFractal3(int order, float length)
{
    // When order = 1 a new line is drawn
    if( order == 1 )
        DrawLine(length);
    else
    {
        // Base line
        DrawFractal3(order - 1, length / 2);
        // Draws line with a +85 degree offset
        Plus(85);
        DrawFractal3(order - 1, length / 2);
        // Draws line with a -85 degree offset
        Minus(85);
        Minus(85);
        DrawFractal3(order - 1, length / 2);
        // Draws line with a -85 degree offset
        Plus(85);
        DrawFractal3(order - 1, length / 2);
    }
}

// Draws a Koch Snowflake
void OptionThree(int order)
{
    int WIDTH = 500;
    int HEIGHT = 500;
    for (int i = 1; i <= order; i++) {
        x = 30;
        y = HEIGHT - 50;
        angle = 0;
        cleardevice();

        DrawFractal3(i, WIDTH - 60);
        outtextxy(150, HEIGHT - 20, "Press any key...");
        getch();
    }
}

void DrawFractal4(int order, int length)
{
    // When order = 1 a new line is drawn
    if (order == 1 ) {
        DrawLine(length);
    } else
    {
        // Basically does this: _ -> _| |_
        DrawFractal4(order - 1, length / 3);
        Plus(90);
        DrawFractal4(order - 1, length / 3);
        Minus(90);
        DrawFractal4(order - 1, length / 3);
        Minus(90);
        DrawFractal4(order - 1, length / 3);
        Plus(90);
        DrawFractal4(order - 1, length / 3);
    }
}

// Draws a type 1 Koch Quadric curve
void OptionFour(int order)
{
    int WIDTH = 600;
    int HEIGHT = 400;

    for (int i = 1; i <= order; i++) {
        x = 30;
        y = HEIGHT - 100;
        angle = 0;
 
        cleardevice();
 
        DrawFractal4(i, WIDTH - 50);
        outtextxy(150, HEIGHT - 20, "Press any key...");
 
        getch();
    }
}
