#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

#define PIPE_READ 0
#define PIPE_WRITE 1
#define MAX_BUF_SIZE 1024

void list_text_files(const char *dir_name, char *output) {
    char command[MAX_BUF_SIZE];
    snprintf(command, sizeof(command), "ls %s/*.txt 2>/dev/null", dir_name); //function ensures that the command is properly formatted and fits within the buffer size 
	FILE *fp = popen(command, "r"); //open a pipe to read the output
    if (fp == NULL) {
        perror("popen");
        exit(EXIT_FAILURE);
    }

    strcpy(output, "Fisiere text in director:\n");
    char buffer[MAX_BUF_SIZE];
    int found = 0;

    while (fgets(buffer, sizeof(buffer), fp) != NULL) {
        strcat(output, buffer); //appends a copy of the source string to the destination string
        found = 1;
    }

    if (!found) {
        strcat(output, "Niciun fisier text gasit.\n");
    }

    pclose(fp);
}

int main() {
    int pipe_client_to_server[2];
    int pipe_server_to_client[2];

    if (pipe(pipe_client_to_server) == -1 || pipe(pipe_server_to_client) == -1) {
        perror("pipe");
        exit(EXIT_FAILURE);
    }

    int pid = fork();
    if (pid == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    } else if (pid == 0) { // Server Process
        close(pipe_client_to_server[PIPE_WRITE]); // close write (Client)
        close(pipe_server_to_client[PIPE_READ]); // close read (Client)

        char dir_name[MAX_BUF_SIZE];
        read(pipe_client_to_server[PIPE_READ], dir_name, sizeof(dir_name)); // read directory

        char output[MAX_BUF_SIZE * 2]; 
        list_text_files(dir_name, output); 

        write(pipe_server_to_client[PIPE_WRITE], output, strlen(output) + 1); // write answer

        close(pipe_client_to_server[PIPE_READ]);
        close(pipe_server_to_client[PIPE_WRITE]);
        return 0;
    }

    // Client Process
    close(pipe_client_to_server[PIPE_READ]); // close write (Server)
    close(pipe_server_to_client[PIPE_WRITE]); // close read (Server)

    char dir_name[MAX_BUF_SIZE];
    printf("Introduceti numele directorului: ");
    scanf("%s", dir_name);

    write(pipe_client_to_server[PIPE_WRITE], dir_name, strlen(dir_name) + 1); // send directory

    char response[MAX_BUF_SIZE * 2]; 
    read(pipe_server_to_client[PIPE_READ], response, sizeof(response)); // read answer

    printf("%s", response); 

    close(pipe_client_to_server[PIPE_WRITE]);
    close(pipe_server_to_client[PIPE_READ]);

    wait(NULL); // wait for server

    return 0;
}
