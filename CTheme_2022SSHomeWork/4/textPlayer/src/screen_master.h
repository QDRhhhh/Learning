#ifndef __SCREEN_MASTER__
#define __SCREEN_MASTER__

#include <string.h>
#include "VKdefine.h"
#include "libgraphics/strlib.h"
#include "libgraphics/graphics.h"
#include "libgraphics/extgraph.h"
#include "logger.h"

#define MAXN 4096
#define TIMER_BLINK500  1
const int mseconds500 = 100;

// A class of TextLabel.
struct TextLabelObject{
	// text message 
	char * msg;
	// position
	double x, y;
	int curPos;
};

// A class of cursor.
struct CursorObject{
	double x, y;
	int visable;
};

void initScreen();

#endif
