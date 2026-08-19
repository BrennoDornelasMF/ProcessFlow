#include <stdio.h>
#include <string.h>

#include "parcer.h"


int main(int argc, char *argv[]){

    // modo workflow
    if(argc > 1){

    }else if(argc == 1){  // modo interativo

        printf("ProcessFlow > ");
        char** tokens = parcer_line();

        if(tokens == NULL){
            printf("Error de leitura");
        }

        for(int i = 0; tokens[i] != NULL; i++){
            printf("token[%d] = \"%s\"\n", i, tokens[i]);      
        }

        free_tokens(tokens);

    }


    return 0;
}