#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#define BUFFER_SIZE 1024
int main(int argc, char* argv[]){
    if (argc != 2) {
        printf("correct usage: ./Q5 filename\n");
        return EXIT_FAILURE;
    }

    char *p = getcwd(argv[1], BUFFER_SIZE);
    printf("%d\n", *p);
    return EXIT_SUCCESS;
}