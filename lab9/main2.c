#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>  //для execlp

#define CHILD 0
#define ERROR 1
#define ERROR_FORK -1
#define ERROR_WAIT -1
#define SUCCESS 0

int main() {
    pid_t pid, ret;
    pid = fork();
    
    if (pid == ERROR_FORK) {
        perror("fork failed: ");
        return ERROR;
    }

    if (pid == CHILD) {  
        execlp("cat", "cat", "text.txt", NULL);
        perror("execlp faild: ");
        return ERROR;
    }
    
    ret = wait(NULL);
    if (ret == ERROR_WAIT) {
        perror("wait failed: ");
        return ERROR;
    }
        
    printf("I'm a parent process\n");
    return SUCCESS;
}
