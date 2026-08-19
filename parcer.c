#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE 200


char** parcer_line(void){
    char linha[MAX_LINE];
    size_t len;
    int cont = 0;
    int capacidade = 8;



    if(fgets(linha, sizeof linha, stdin) == NULL){
        return NULL; // EOF Ctrl+D
    }
   
    len = strlen(linha);
    if(len > 0 && linha[len -1] == '\n') {
        linha[len - 1] = '\0';
    }

    char** tokens = malloc(capacidade * sizeof(char*));
    if(tokens == NULL){
        return NULL;
    }



}