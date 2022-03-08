#include <sys/types.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define SUCCESS 0;
#define ERROR -1;
#define PUTENV_EXIT_ERROR 1;
#define TIME_EXIT_ERROR 2;
#define CTIME_EXIT_ERROR 3;
#define LOCALTIME_EXIT_ERROR 4;

extern char *tzname[];

main() {
    time_t now;
    struct tm *sp;
       
    int result_putenv = putenv ("TZ=America/Los_Angeles");
    if (result_putenv == ERROR){
		perror("Error - putenv");
		exit(PUTENV_EXIT_ERROR);
	}
    
    int all_time = time(&now);
    if (all_time == ERROR) {
        perror("Error - time");
        exit(TIME_EXIT_ERROR);
    }
    
    char* str_time;
    str_time = ctime(&now);
    if (Ctime == NULL){
        perror("Error - ctime");
        exit(CTIME_EXIT_ERROR);
    }
    printf("%s", str_time);
    
    sp = localtime(&now);
    if (sp == NULL){
        perror("Error - localtime");
        exit(LOCALTIME_EXIT_ERROR);
    }
    
    printf("%d/%d/%02d %d:%02d %s\n",
        sp->tm_mon + 1, 
        sp->tm_mday,
        sp->tm_year, 
        sp->tm_hour,
        sp->tm_min, 
        tzname[sp->tm_isdst]);
    
    return SUCCESS;
}
