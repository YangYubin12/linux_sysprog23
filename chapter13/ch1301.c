#include<sys/socket.h>
#include<unistd.h>
#include<netdb.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<stdlib.h>
#include<string.h>
#include<stdio.h>

#define PORTNUM 9001

int main() {
    int sd;
    char buf[256];
    struct sockaddr_in sin;

    if((sd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("socket");
        exit(1);
    }

    memset((char *)&sin, '\0', sizeof(sin));
    sin.sin_family = AF_INET;
    sin.sin_port = htons(PORTNUM);
    sin.sin_addr.s_addr = inet_addr("172.31.228.149"); 

    if(connect(sd, (struct sockaddr *)&sin, sizeof(sin))) {
        perror("connect");
        exit(1);
    }

    if(recv(sd, buf, sizeof(buf), 0) == -1) {
        perror("recv");
        exit(1);
    }

    printf("** From Server : %s\n", buf);
        
    strcpy(buf, "I want a HTTP Service.");
    if(send(sd, buf, sizeof(buf) + 1, 0) == -1) {
        perror("send");
        exit(1);
    }
    
    close(sd);
    return 0;
}
