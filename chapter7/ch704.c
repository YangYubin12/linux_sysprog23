#include<unistd.h>
#include<stdlib.h>
#include<stdio.h>

int main() {
    printf("--> Brfore exec function\n");

    if(execlp("ls", "ls", "-a", (char *)NULL) == -1) {
        perror("execlp");
        exit(1);
    }

    printf("--> After exec funtion\n");
    return 0;
}
