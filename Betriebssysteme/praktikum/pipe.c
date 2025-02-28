#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    int pipep_c[2];  // Pipe for parent to child communication
    int pipec_p[2];  // Pipe for child to parent communication

    
    if (pipe(pipep_c) == -1 || pipe(pipec_p) == -1) {
        perror("pipe");
        exit(EXIT_FAILURE);
    }

    int pid = fork(); 
    if (pid == -1) {    
        perror("fork");
        exit(EXIT_FAILURE);
    }

    if (pid > 0) {  
        close(pipep_c[0]); 
        close(pipec_p[1]); 

        int num1, num2;
        printf("Doua numere te rog: ");
        scanf("%d %d", &num1, &num2); 

       
        write(pipep_c[1], &num1, sizeof(num1));
        write(pipep_c[1], &num2, sizeof(num2));
        close(pipep_c[1]); 

        int sum;
        read(pipec_p[0], &sum, sizeof(sum));
        close(pipec_p[0]); 

        printf("Suma: %d\n", sum); 

        wait(NULL); 
    } else {  
        close(pipep_c[1]); 
        close(pipec_p[0]); 

        int num1, num2;
        read(pipep_c[0], &num1, sizeof(num1)); 
        read(pipep_c[0], &num2, sizeof(num2)); 
        close(pipep_c[0]); 

        int sum = num1 + num2; 

        write(pipec_p[1], &sum, sizeof(sum)); 
        close(pipec_p[1]); 

        exit(EXIT_SUCCESS); 
    }

    return 0;
}

