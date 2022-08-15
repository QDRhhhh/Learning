#include <math.h>
#include "turtlePencil.h"
#include "utils.h"

// The variable represents the direction of the 
// cursor.
// This angle is measured in degrees counterclockwise 
// from the 3 o'clock position along the x-axis,
// as in traditional mathematics.
static double ANGLE = 0;

// You must call this function before using other
// interface in this library to initialize the 
// necessary things.
// What you should also know is that the initial 
// angle of the cursor is 3 o'clock position along
// the x-axis.
// And the cursor will be put at the center of the
// screen.
void init(){
    InitGraphics();
    double x = GetWindowWidth() / 2;
    double y = GetWindowHeight() / 2;
    MovePen(x, y);
    ANGLE = 0;
    return;
}

// Be used to draw a line in the current direction
// of the cursor with the distance of dis(double).
void forward(double dis){

    double x = GetCurrentX();
    double y = GetCurrentY();
    double dx = dis * cos(ANGLE);
    double dy = dis * sin(ANGLE);
    DrawLine(dx, dy);
    return;
}

// Be used to change the current angle of cursor 
// anti-clockwise by delta angle ang(double).
void turn(double ang){
    ANGLE += ang / 180 * 3.1415926535;
}

// Be used to move the cursor int the current 
// direction of the cursor without track being
// drawn with the distance of dis(double).
void move(double dis){
    double x = GetCurrentX() + dis * cos(ANGLE);
    double y = GetCurrentY() + dis * sin(ANGLE);
    MovePen(x, y);
}

// Be used to get the angle of the current direction
// of the cursor.
// This angle is measured in degrees counterclockwise.
double showAngle(){
    return ANGLE;
}

// Be used to get the width and the height of the screen.
double getScreenX(){
    return GetWindowWidth();
}
double getScreenY(){
    return GetWindowHeight();
}
