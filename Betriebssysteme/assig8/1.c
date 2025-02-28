#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>

#define PIPE_NUMBERS "/root/SO/assig8/pipe_numbers"
#define PIPE_LETTERS "/root/SO/assig8/pipe_letters"

#define BUFFER_SIZE 1024

void create_pipes(){
    if (access(PIPE_NUMBERS, F_OK) == -1 || access(PIPE_LETTERS, F_OK) == -1) {
        if(mkfifo(PIPE_NUMBERS, 0666) == -1){
            perror("mkfifo");
            exit(EXIT_FAILURE);
        }
        if(mkfifo(PIPE_LETTERS, 0666) == -1){
            perror("mkfifo");
            exit(EXIT_FAILURE);
        }
    } else {
        printf("Fișierele FIFO există deja.\n");
        exit(EXIT_SUCCESS);
    }
}



void process1(){
    char buffer[BUFFER_SIZE];
    int fd_numbers = open(PIPE_NUMBERS, O_WRONLY);
    int fd_letters = open(PIPE_LETTERS, O_WRONLY);
    if(fd_numbers == -1 || fd_letters == -1){
        perror("open");
        exit(EXIT_FAILURE);
    }
    while(fgets(buffer, BUFFER_SIZE, stdin) != NULL){
        if(strlen(buffer) > 30){
            continue;
        }
        for(int i = 0; i < strlen(buffer); i++){
            if(isdigit(buffer[i])){
                write(fd_numbers, &buffer[i], 1);
            }else if(isalpha(buffer[i])){
                write(fd_letters, &buffer[i], 1);
            }
        }
    }
    close(fd_numbers);
    close(fd_letters);
}

void process2(){
    char ch;
    int fd = open(PIPE_NUMBERS, O_RDONLY);
    if(fd == -1){
        perror("open");
        exit(EXIT_FAILURE);
    }
    while(read(fd, &ch, 1) > 0){
        putchar(ch);
        fflush(stdout);
    }
    close(fd);
}

void process3(){
    char ch;
    int fd = open(PIPE_LETTERS, O_RDONLY);
    if(fd == -1){
        perror("open");
        exit(EXIT_FAILURE);
    }
    while(read(fd, &ch, 1) > 0){
        putchar(toupper(ch));
        fflush(stdout);
    }
    close(fd);
}

int main(){
    create_pipes();
    int pid1 = fork();
    if(pid1 == -1){
        perror("fork()");
        exit(EXIT_FAILURE);
    }
    if(pid1 == 0){ //Child process 1
        process1();
        exit(EXIT_SUCCESS);
    }
    int pid2 = fork();
    if(pid2 == -1){
        perror("fork()");
        exit(EXIT_FAILURE);
    }
    if(pid2 == 0){  //Child process 2
        process2();
        exit(EXIT_SUCCESS);
    }
    int pid3 = fork();
    if(pid3 == -1){
        perror("fork()");
        exit(EXIT_FAILURE);
    }
    if(pid3 == 0){ //Child process 3
        process3();
        exit(EXIT_SUCCESS);
    }
    wait(NULL);
    wait(NULL);
    wait(NULL);
    
    return 0;
}
