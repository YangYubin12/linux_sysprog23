#include<sys/types.h>
#include<unistd.h>
#include<stdlib.h>
#include<stdio.h>
// 가장 많이 나오는 포맷, 중요

int main() {
    pid_t pid;

    switch (pid = fork()){
    case -1 :/* fork failed */
        perror("fork");
        break;
    case 0 : /* child process */
        printf("-->Child Process\n");
        if(execlp("ls", "ls", "-a", (char *)NULL) == -1) {
            perror("execlp");
            exit(1);
        }
        exit(0);
        break;
    default: /* parent process */
        printf("-->Parent process - My PID:%d\n", (int)getpid());
        break;
    }
}
