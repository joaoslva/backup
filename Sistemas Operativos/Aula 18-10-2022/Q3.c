#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char* argv[]) {
    struct stat info;

    if (argc < 2) {
        fprintf(stderr, "usage: %s file\n", argv[0]);
        return EXIT_FAILURE;
    }
    int total_bytes = 0;
    int total_blocks = 0;
    for(int i = 1; i < argc; i++){
        if (stat(argv[i], &info) == -1) {
            fprintf(stderr, "fsize: Can’t stat %s\n", argv[1]);
            return EXIT_FAILURE;
        }

        total_bytes += (int)info.st_size;
        total_blocks += (int)info.st_blocks;

        printf("File Name: %s\n size: %d bytes, disk_blocks: %d, date: %s, user: %d\n\n",
               argv[i], (int)info.st_size, (int)info.st_blocks, ctime(&info.st_ctim), info.st_uid);
    }
    printf("Total byes: %d; Total blocks: %d\n", total_bytes, total_blocks);
    return EXIT_SUCCESS;
}