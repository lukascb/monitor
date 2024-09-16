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
        if ((pfd = open(FIFO,O_RDWR|O_NONBLOCK)) == -1){
            if(errno == 17 || 11 ){
                continue;
            }else {
                printf("data.txt => %s - %d",strerror(errno), errno);
                break;
            } 
        }
        sleep(1);
        if(read(pfd,dado,sizeof(dado)) == -1){
            if(errno == 17 || 11 ){
                continue;
            }else {
                printf("data.txt => %s - %d",strerror(errno), errno);
                break;
            }    
        }
        if(strcmp(dado,"continuar") == 0){
            if(write(pfd,continuar,strlen(continuar)+1)== -1){
                if(errno == 17 || 11 ){
                    continue;
                }else {
                    printf("data.txt => %s - %d",strerror(errno), errno);
                    break;
                } 
            }
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
            if(read(pfd,dado,sizeof(dado)) == -1){
               if(errno == 17 || 11 ){
                    continue;
                }else {
                    printf("data.txt => %s - %d",strerror(errno), errno);
                    break;
                } 
            }
            if(write(pfd,finalizado,strlen(finalizado)+1) == -1){
                if(errno == 17 || 11 ){
                    continue;
                }else {
                    printf("data.txt => %s - %d",strerror(errno), errno);
                    break;
                } 
            }
        }
        close(pfd);
        time(&end);
        t = difftime(end,start);
        result = fmod(t,mod);
        printf("###MONITOR### => %f\n",difftime(end,start));
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
    if(fprintf(fd,"%s => %s\n",dateString,content) < 0){
            if(errno != 17 || 11){
                printf("log.txt => %s",strerror(errno));
                return 1;
            }
        }
    fclose(fd);
    printf("%s\n",dateString);
    return 0;
}