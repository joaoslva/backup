#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char* argv[]) {
        FILE* file;
        file = fopen(argv[1], "r");
        int c;

        while(1){
            c = fgetc(file);
            if(c == EOF) break;

            if(strcmp(argv[2], "-u") == 0 || argc > 2){
                c = toupper(c);
            }
            else if (strcmp(argv[2], "-l") == 0 || argc > 2) {
                c = tolower(c);
            }


            printf("%c", c);
        }
        fclose(file);
    return EXIT_SUCCESS;

}
