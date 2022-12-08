#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
int main(int argc, char* argv[]) {
    //printf("%d", getpid());
/* fork a child process */
    fork();
    pid_t a = getpid();
    //printf("%d", a);
/* fork another child process */
    fork();
    pid_t b = getpid();
    //printf("%d", b);
/* and fork another */
    fork();
    pid_t c = getpid();
    printf("%d\n", c);
    return EXIT_SUCCESS;
}