#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "parcer.h"

#define MAX_LINE 200


char** parcer_line(void){
    char linha[MAX_LINE];
    size_t len;
    int cont = 0;
    int capacidade = 8;



    if(fgets(linha, sizeof linha, stdin) == NULL){
        exit; // EOF Ctrl+D
    }
   
    len = strlen(linha);
    if(len > 0 && linha[len -1] == '\n') {
        linha[len - 1] = '\0';
    }

    char** tokens = malloc(capacidade * sizeof(char*));
    if(tokens == NULL){
        return NULL;
    }

    char* tok = strtok(linha, " /t");
    while (tok != NULL){

        if(cont >= capacidade -1) {
            capacidade *=2;
            char** tmp = realloc(tokens, capacidade * sizeof(char*));

            if(tmp == NULL){
                for (int i = 0; i < cont; i++) {
                    free(tokens[i]);
                }
                free(tokens);
                return NULL;
            }
            tokens = tmp;
        }

        size_t tok_len = strlen(tok);
        char* copy = malloc(tok_len + 1);
        if(copy == NULL){
            for(int i = 0; i < cont; i++){
                free(tokens[i]);
            }
            free(tokens);
            return NULL;
        }

        strcpy(copy, tok);
        tokens[cont] = copy;
        cont++;

        tok = strtok(NULL, " \t");
    }
    tokens[cont] = NULL;
    return tokens;
}

void free_tokens(char** tokens){
    if (tokens == NULL) return;

    for (int i = 0; tokens[i] != NULL; i++){
        free(tokens[i]);
    }
    free(tokens);
}


