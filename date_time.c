#include <stdio.h>
#include <time.h>
#include "date_time.h"


const char *currentTime(){

static char buf[32];
time_t now = time(NULL);
struct tm *t = localtime(&now);
if (!t) {buf[0] = '\0'; return buf;}
strftime(buf, sizeof(buf), "%d/%m/%Y | %H:%M:%S", t);

  return buf;

}