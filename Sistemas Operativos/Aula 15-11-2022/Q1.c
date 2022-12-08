#include <sys/wait.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#define READ_END 0
#define WRITE_END 1
#define LINESIZE 4096

int main(int argc, char* argv[]) {
    int nbytes, fd[2];
    pid_t pid;
    FILE* file = fopen(argv[1],"r");
    char line[LINESIZE];

    if (pipe(fd) < 0) {
        perror("pipe error");
        exit(EXIT_FAILURE);
    }

    if ((pid = fork()) < 0) {
        perror("fork error");
        exit(EXIT_FAILURE);
    }

    else if (pid > 0) {
        /* parent */
        close(fd[READ_END]);
        printf("Parent process with pid %d\n", getpid());
        printf("Messaging the child process (pid %d):\n", pid);
        //snprintf(line, LINESIZE, "Hello! I’m your parent pid %d!\n", getpid());

        char ch;
        for (ch = getc(file); ch != EOF; ch = getc(file)){
            if ((write(fd[WRITE_END], &ch, sizeof(ch))) < 0) {
                fprintf(stderr, "Unable to write to pipe: %s\n", strerror(errno));
            }
        }
        /*if ((nbytes = write(fd[WRITE_END], line, strlen(line))) < 0) {
            fprintf(stderr, "Unable to write to pipe: %s\n", strerror(errno));
        }*/
        close(fd[WRITE_END]);
        /* wait for child and exit */
        if ( waitpid(pid, NULL, 0) < 0) {
            fprintf(stderr, "Cannot wait for child: %s\n", strerror(errno));
        }

    exit(EXIT_SUCCESS);
    }

    else {
        /* child */
        close(fd[WRITE_END]);
        printf("Child process with pid %d\n", getpid());
        printf("Receiving message from parent (pid %d):\n", getppid());
        char ch;
        while ((nbytes = read(fd[READ_END], &ch, sizeof(ch))) > 0) {
            printf("%c", ch);
        }
        /*
        if ((nbytes = read(fd[READ_END], line, LINESIZE)) < 0 ) {
            fprintf(stderr, "Unable to read from pipe: %s\n", strerror(errno));
        }
        */
        close(fd[READ_END]);
        /* write message from parent */
        //write(STDOUT_FILENO, line, nbytes);
        /* exit gracefully */
        exit(EXIT_SUCCESS);
    }
}