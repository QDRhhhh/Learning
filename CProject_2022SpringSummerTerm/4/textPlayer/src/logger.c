#include "logger.h"

static int doLog;

void INFO(char * msg){
	if(doLog) printf("[INFO] %s", msg);
}

void ERROR(char * msg){
	if(doLog) printf("[ERRO] %s", msg);
}

void FATAL(char * msg){
	if(doLog) printf("[FATA] %s", msg);
}

void changeLoggerStatus(){
	doLog = !doLog;
	INFO("Logger open\n");
}
