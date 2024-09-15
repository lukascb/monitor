#include <stdio.h>
#include <math.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <linux/stat.h>
#include <stdlib.h>
#include <time.h>
#include <errno.h>
#include "log.h"
#define FIFO "./data.txt"


int main(){
    int pfd;
    char dado[20];
    char *finalizado = "finalizado";
    char *continuar = "continuar";
    time_t start,end,timestamp;
    struct tm date;
    double t,result = -1.;
    double mod = 10.0;

    time(&start);
    while (1){
        pfd = open(FIFO,O_RDWR|O_NONBLOCK);
        sleep(1);
        read(pfd,dado,sizeof(dado));
        if(strcmp(dado,"continuar") == 0){
            write(pfd,continuar,strlen(continuar)+1);
        }
        if(strcmp(dado,"finalizado") == 0){
            log_to("./log.txt", "./login: Finalizado");
            pid_t p = fork(); 
            if(p<0){ 
                perror("Falha ao gerar processo"); 
                log_to("./log.txt", "./login: Falha na reabertura.");
                exit(1); 
            } 
            if(p == 0){
                printf("Reiniciando ./leitor\n");
                log_to("./log.txt", "./login: Reiniciado");
                execl("./leitor",NULL);
            }else{
                continue;
            }

            break;
        }
        if( result == 0.){
            read(pfd,dado,sizeof(dado));
            write(pfd,finalizado,strlen(finalizado)+1);
        }
        close(pfd);
        time(&end);
        t = difftime(end,start);
        result = fmod(t,mod);
        printf("###MONITOR### => %f\n",difftime(end,start));
        printf("MOD: %f\n",result);
    }
}


int log_to(char *file, char *content){
    
    int len;
    FILE *fd;
    time_t timestamp;
    struct tm dt;
    char *dateString;
    char *final;
    time(&timestamp);
    localtime_r(&timestamp, &dt);
    dateString = asctime(&dt);

    fd = fopen("./log.txt","a");
    if (fd == NULL) { 
        printf("Erro ao abrir o log.txt\n"); 
        return 1; 
    } 

    len = strlen(dateString);
    for (int i=0;i<=len;i++){
        if(dateString[i] == '\n'){
            dateString[i] = '\0';
        }
    }
    //dateString[len] = '\0';
    fprintf(fd,"%s => %s\n",dateString,content);
    fclose(fd);

    printf("%s\n",dateString);
    return 0;
}