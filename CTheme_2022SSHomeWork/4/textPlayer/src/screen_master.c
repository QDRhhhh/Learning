#include "screen_master.h"

struct TextLabelObject onlyLabel;
struct CursorObject onlyCursor;

// The exist of the program. 
void finishEnter(){
	ExitGraphics();
	INFO("Player Off!\n");
	printf("The text you input is : \n[ %s ]\n", onlyLabel.msg);
}

// Be used to move the cursor.
void moveCur(int del){
	if(!(onlyLabel.curPos + del < 0 || onlyLabel.curPos + del > strlen(onlyLabel.msg))){
		onlyLabel.curPos += del;
	}
	return;
}

// Show the text of the label.
void showLabel(){
	InitGraphics();
	INFO("show label\n");
	MovePen(onlyLabel.x, onlyLabel.y);
	char beforeStr[MAXN] = "";
	memcpy(beforeStr, onlyLabel.msg, onlyLabel.curPos);
	DrawTextString(beforeStr);
	onlyCursor.x = GetCurrentX();
	onlyCursor.y = GetCurrentY();
	DrawTextString(onlyLabel.msg + onlyLabel.curPos);
}

// Draw the cursor. (include show and unshow)
void DrawCursor(){
	MovePen(onlyCursor.x, onlyCursor.y);
	double fontHight = GetFontHeight();
	DrawLine(0,fontHight);
}

// Show screen;
void ShowScreen(){
	showLabel();
	int erasemode;
	INFO("Cursor Blink!\n");
	erasemode = GetEraseMode();
	SetEraseMode(onlyCursor.visable);
    DrawCursor();
	SetEraseMode(erasemode);
	onlyCursor.visable = !onlyCursor.visable;
}

// Be used to state the keyboard event.
void CharEventProcess(char c){
	INFO("check char event\n");
	char newMsg[MAXN] = "", tmp[MAXN] = "";
	memcpy(newMsg, onlyLabel.msg, onlyLabel.curPos);
    int len, del;
    char newStr[2] = {};
    char str[2];
    switch (c) {
    case VK_RETURN:
    	INFO("Find a enter input\n");
		finishEnter();
        break;
    case VK_BACK:
    	INFO("Find a backspace input\n");
    	len = strlen(newMsg)-1 > 0 ? strlen(newMsg)-1 : 0;
    	newMsg[len] = '\0';
		del = -1;
		break;
	
    default:
    	INFO("Find a char input\n");
		strcpy(tmp,newMsg);
    	newStr[0] = c;
		strcpy(newMsg, strcat(tmp, newStr));
		del = 1;
        break;
    }
	
	INFO("Dealing\n");
	strcat(newMsg, onlyLabel.msg+onlyLabel.curPos);
    onlyLabel.msg = CopyString(newMsg);
	onlyLabel.curPos += del;

	INFO("Update Msg to");
	INFO(newMsg);
	INFO("\n");
	showLabel();
}

// Be used to check keyboard event.
void KeyboardEventProcess(int key, int event){
    switch (event) {
	 	case KEY_DOWN:
			switch (key) {
			    case VK_F1:
			    	changeLoggerStatus();
			    	break;
				case VK_LEFT:
					moveCur(-1);
					break;
				case VK_RIGHT:
					moveCur(+1);
					break;
			}
			ShowScreen();
			break;
		case KEY_UP:
			break;
	}	 
}

// Be used to do cursor bling bling.
void TimerEventProcess(int timerID){
	int erasemode;
	switch (timerID) {
	    case TIMER_BLINK500:
			ShowScreen();
			break;
	    default:
			break;
	}
}

// Be uesed to initialize the usefull windows.
void initWindowss(){
	InitGraphics();
	InitConsole();
	SetWindowTitle("Welcome to textPlayer!"); 
	INFO("Windows Initialization Finished!\n");
}

// Be uesed to initialize the only TextLabelObject.
void initLabel(){
	onlyLabel.msg = "";
	onlyLabel.x = GetWindowWidth()/5;
	onlyLabel.y = GetWindowHeight()/5;
	INFO("Label Initialization Finished!\n");
}

// Be used to initialize the screen.
// Call it before you use anything in this lib.
void initScreen(){
	initWindowss();
	initLabel();
	registerKeyboardEvent(KeyboardEventProcess);
    registerCharEvent(CharEventProcess);
	registerTimerEvent(TimerEventProcess);
    startTimer(TIMER_BLINK500, mseconds500);
    return;
}

