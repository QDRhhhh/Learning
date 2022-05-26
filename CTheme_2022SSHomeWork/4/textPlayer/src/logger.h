#ifndef __LOGGER__
#define __LOGGER__

#include "stdio.h"

void INFO(char * msg);

void ERROR(char * msg);

void FATAL(char * msg);

void changeLoggerStatus();

#endif
