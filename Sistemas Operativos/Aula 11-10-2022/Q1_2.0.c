#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#define MAX_STR_SIZE 64

int main(int argc, char* argv[]) {
    char* p1 = (char*)malloc(MAX_STR_SIZE * sizeof(char));
    char* p2 = (char*)malloc(MAX_STR_SIZE * sizeof(char));
    char* p3 = (char*)malloc(MAX_STR_SIZE * sizeof(char));

    strcpy(p1, argv[1]);
    // Tolower string
    for(int i = 0; p1[i] != '\0'; i++){
        p1[i] = tolower(p1[i]);
    }

    printf("argv[1] tolower(): ");
    printf("%s", p1);
    printf("\n");

    //See if is inside
    strcpy(p2, argv[1]);
    strcpy(p3, argv[2]);

    int detected = 0;
    int error = 0;

    if(strlen(p2) > strlen(p3)){
        error = 1;
    }

    /*
    else{
        for(int i = 0; i < strlen(p3) - strlen(p2); i++){
            for(int j = 0; j < strlen(p2); j++){
                if(tolower(p2[j]) != tolower(p3[i+j])){
                    detected = 1;
                }
                else{
                    detected = 0;
                    break;
                }
            }
            if(detected) break;
        }
    }
    */
    if(strstr(p3, p2) != NULL) detected = 1;

    if(error){
        printf("Not possible \n");
    }
    else{
        printf("Is argv[1] in argv[2]: ");
        if(detected) printf("True \n");
        else printf("False \n");
    }

    //See how many are in
    int count = 0;
    char* ret = strstr(p3, p2);

    while(ret != NULL){
        count++;
        *p3 = *(ret + strlen(p2));
        ret = strstr(p3, p2);
    }

    printf("Occurrences of argv[1] in argv[2]: ");
    printf("%d \n", count);


}