#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>

int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

void find_min_max(int *numbers, int size, int *min, int *max) {
    *min = numbers[0];
    *max = numbers[0];
    
    for (int i = 1; i < size; i++) {
        if (numbers[i] < *min)
            *min = numbers[i];
        if (numbers[i] > *max)
            *max = numbers[i];
    }
}

int main() {
    int N, k;
    printf("Introduceti nr de numere intregi (N): ");
    scanf("%d", &N);
    
    
    while (getchar() != '\n');
    
    int fd = open("numere.txt", O_RDONLY);
    if (fd == -1) {
        perror("open");
        exit(EXIT_FAILURE);
    }
    
    int numbers[N];
    printf("Introduceti %d nr intregi in fisierul numere.txt:\n", N);
    for (int i = 0; i < N; i++) {
        if (scanf("%d", &numbers[i]) != 1) {
            perror("scanf");
            exit(EXIT_FAILURE);
        }
    }
    
    close(fd);
	
	qsort(numbers, N, sizeof(int), compare);
    
    printf("Introduceti valoarea lui k (1 <= k <= %d): ", N);
    scanf("%d", &k);
    
    int min, max;
    int pid = fork();
    
    if (pid == 0) { // Procesul copil pentru gasirea minimului
        find_min_max(numbers, N, &min, &max);
		printf("Valoarea minima este: %d\n", min);
        exit(min);
    } else if (pid > 0) { // Procesul parinte
        int status;
        wait(&status);
        min = WEXITSTATUS(status);  //returns the exit status of the child
        
        pid = fork();
        if (pid == 0) { // Procesul copil pentru gasirea maximului
            find_min_max(numbers, N, &min, &max);
			printf("Valoarea maxima este: %d\n", max);
            exit(max);
        } else if (pid > 0) { // Procesul parinte
            wait(&status);
            max = WEXITSTATUS(status);
            
            if (k < 1 || k > N) {
                printf("Valoare invalida pentru k\n");
                exit(EXIT_FAILURE);
            }
            
            printf("Al %d-lea element când lista este sortata in ordine crescatoare este: %d\n", k, numbers[k - 1]);
        } else {
            perror("fork() max");
            exit(EXIT_FAILURE);
        }
    } else {
        perror("fork() min");
        exit(EXIT_FAILURE);
    }
    
    return 0;
}








