#ifndef __TURTLE_PENCIL__
#define __TURTLE_PENCIL__

#include "libgraphics/graphics.h"

// You must call this function before using other
// interface in this library to initialize the 
// necessary things.
// What you should also know is that the initial 
// angle of the cursor is 3 o'clock position along
// the x-axis.
// And the cursor will be put at the center of the
// screen.
void init();

// Be used to draw a line in the current direction
// of the cursor with the distance of dis(double).
void forward(double dis);

// Be used to change the current angle of cursor 
// anti-clockwise by delta angle ang(double).
void turn(double ang);

// Be used to move the cursor int the current 
// direction of the cursor without track being
// drawn with the distance of dis(double).
void move(double dis);

// Be used to get the angle of the current direction
// of the cursor.
// This angle is measured in degrees counterclockwise.
double showAngle();

// Be used to get the width and the height of the screen.
double getScreenX();
double getScreenY();

#endif
