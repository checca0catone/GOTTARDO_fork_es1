#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>

int main() {
    int N;

    printf("Inserisci il numero di processi da creare: ");
    scanf("%d", &N);

    if (N <= 0) {
        printf("Il numero deve essere positivo!\n");
        return 1;
    }

    for (int i = 1; i <= N; i++) {
        pid_t pid = fork();

        if (pid < 0) {
            perror("Errore nella fork");
            return 1;
        }

        if (pid == 0) {
            printf("Processo figlio %d → PID = %d, PPID = %d\n",
                   i, getpid(), getppid());
            exit(0);
        }
    }

    for (int i = 0; i < N; i++) {
        wait(NULL);
    }

    return 0;
}