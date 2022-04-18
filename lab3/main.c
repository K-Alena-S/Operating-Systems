#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

#define SUCCESS 0
#define ERROR_OPENING 1
#define ERROR_CLOSING 2
#define ERROR_SET 3
#define ERROR_SETUID -1

int open_file() {
    FILE* file = fopen("text.txt", "r");
    if (file == NULL) {
        perror("Open - failed: ");
        return ERROR_OPENING;
    }

    printf("File opened\n");
    int res_close = fclose(file);
    if (res_close == EOF){
        perror("Close - faild: ");
        return ERROR_CLOSING;
    }
    return SUCCESS;
}

void print_id() {
    printf("\n Real ID = %d\n", getuid());
    printf("Effective ID = %d\n", geteuid());
}

int main() {
    print_id();

    int res = open_file();

    int res_setuid = setuid(getuid());
    if (res_setuid == ERROR_SETUID) {
        perror("Setuid - faild: ");
        return ERROR_SET;
    }

    print_id();
    res =  open_file();

    return res;
}
