#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {

    for(int i = 1; i < argc; i++){
        FILE* file;
        char* line = NULL;
        size_t len = 0;
        ssize_t read;

        file = fopen(argv[i], "r");
        while((read = getline(&line, &len, file)) > 0){
            printf("%s", line);
        }
        fclose(file);

    }
    return(EXIT_SUCCESS);
}
