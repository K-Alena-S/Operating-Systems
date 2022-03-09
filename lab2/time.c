#include <sys/types.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define SUCCESS 0
#define ERROR -1
#define PUTENV_EXIT_ERROR 1
#define TIME_EXIT_ERROR 2
#define CTIME_EXIT_ERROR 3
#define LOCALTIME_EXIT_ERROR 4

extern char *tzname[];

int main() {
    time_t now;         //определяем переменную now типа time_t  
    struct tm *sp;      
       
    int result_putenv = putenv ("TZ=America/Los_Angeles");
    if (result_putenv == ERROR){
	perror("Error - putenv");
	return PUTENV_EXIT_ERROR;
    }
    
    int all_time = time(&now);
    if (all_time == ERROR) {
        perror("Error - time");
        return TIME_EXIT_ERROR;
    }
    
    char* str_time;
    str_time = ctime(&now);
    if (str_time == NULL){
        perror("Error - ctime");
        return CTIME_EXIT_ERROR;
    }
    printf("%s", str_time);
    
    sp = localtime(&now);
    if (sp == NULL){
        perror("Error - localtime");
        return LOCALTIME_EXIT_ERROR;
    }
    
    printf("%d/%d/%02d %d:%02d %s\n",   //выводятся значения полей структуры tm
        sp->tm_mon + 1, 
        sp->tm_mday,
        sp->tm_year + 1900, 
        sp->tm_hour,
        sp->tm_min, 
        tzname[sp->tm_isdst]);           //3/8/2022 21:01 PST (месяц/день/год время часовой пояс)
    
    return SUCCESS;
}
