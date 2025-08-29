#include <stdio.h>
#include <time.h>
#include "date_time.h"
#include <string.h>


const char *currentTime(){

static char buf[32];
time_t now = time(NULL);
struct tm *t = localtime(&now);
if (!t) {buf[0] = '\0'; return buf;}
strftime(buf, sizeof(buf), "%d/%m/%Y | %H:%M:%S", t);

  return buf;

}
//Read deadline from file
int PastDeadline(const char *deadline)
{
  int d, m, y, H, M;
  if (sscanf(deadline, "%d.%d.%d %d:%d", &d, &m, &y, &H, &M) == 5 || sscanf(deadline, "%d-%d-%d %d:%d", &d, &m, &y, &H, &M) == 5) {
    }
    //Possibility without time
  else if(sscanf(deadline, "%d.%d.%d" , &d, &m, &y) == 3 || sscanf(deadline,"%d-%d-%d" , &d, &m, &y) == 3){
    H=0;
    M=0;
  }else{
    return 0;
  }


  struct tm tm_deadline = {0};
  tm_deadline.tm_mday = d;
  tm_deadline.tm_mon  = m - 1;
  tm_deadline.tm_year = y - 1900;
  tm_deadline.tm_hour = H;
  tm_deadline.tm_min  = M;

  time_t t_deadline = mktime(&tm_deadline);
  time_t now = time(NULL);

  return difftime(now, t_deadline) > 0;
}
