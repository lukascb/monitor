#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <linux/stat.h>
#include <stdlib.h>
#include <errno.h> 

#define FIFO "./data.txt"

int main(void){
    mkfifo(FIFO,O_CREAT|O_RDWR|0640);
    char dado[20];
    char *finalizado = "finalizado";
    char *continuar = "continuar";

    int pfd = open(FIFO,O_RDWR|O_NONBLOCK);
    int w = write(pfd,continuar,strlen(continuar)+1);
    

    if(w == -1){
        perror("data.txt");
        return 1;
    }

    
    while (1){
        pfd = open(FIFO,O_RDWR|O_NONBLOCK);
        sleep(1);
        read(pfd,dado,sizeof(dado));
        printf("Dado=>%s\n",dado);
        
        if(strcmp(dado,"continuar") == 0){
            write(pfd,continuar,strlen(continuar)+1);
        }

        if(strcmp(dado,"finalizado") == 0){
            write(pfd,"finalizado",strlen(finalizado)+1);
            break;
        }
        close(pfd);
    }
    close(pfd);
}