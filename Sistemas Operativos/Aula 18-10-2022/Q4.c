#include <stdio.h>
#include <time.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <fcntl.h>


int main(int argc, char* argv[]){
    struct stat info;
    char t[ 100 ] = "";

    if (argc != 2) {
        printf("correct usage: ./Q4 filename\n");
        return EXIT_FAILURE;
    }

    int fd = open(argv[1], O_RDONLY);

    if (fd == -1) {
        FILE* fp = fopen(argv[1], "w");
        chmod(argv[1], 644);
        return EXIT_SUCCESS;
    }

    else if(fd >= 0){
        strftime(t, 100, "%d/%m/%Y %H:%M:%S", localtime( &info.st_mtime));
    }
    return EXIT_SUCCESS;
}