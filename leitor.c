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
    char dado[20];
    char *finalizado = "finalizado";
    char *continuar = "continuar";

    if (mkfifo(FIFO,O_CREAT|O_RDWR|0640) != 0){
        printf("data.txt => %s: id: %d",strerror(errno),errno);
    }
    
    int pfd = open(FIFO,O_RDWR|O_NONBLOCK);
    int w = write(pfd,continuar,strlen(continuar)+1);
   
    
    while (1){
        if(read(pfd,dado,sizeof(dado)) == -1){
            if(errno != 17){
                printf("data.txt => %s",strerror(errno));
                break;
            }
        }
        printf("./leitor => Dado: %s\n",dado);
        
        if(strcmp(dado,"continuar") == 0){
            if(write(pfd,continuar,strlen(continuar)+1) == -1){
                if(errno != 17){
                    printf("data.txt => %s",strerror(errno));
                    break;
                }
            }
        }

        if(strcmp(dado,"finalizado") == 0){
            if(write(pfd,"finalizado",strlen(finalizado)+1) == -1){
               if(errno != 17){
                printf("data.txt => %s",strerror(errno));
                break;
               }
            }
            break;
        }
        sleep(1);
    }
    close(pfd);
}
