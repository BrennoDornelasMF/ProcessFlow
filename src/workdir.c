#include <unistd.h>
#include <stdio.h>

#include "../include/workdir.h"

void workdir_process(char** tokens){

    if (tokens[1] == NULL){
        printf("Erro: workdir precisa de um diretorio\n");
        return;
    }

    if (chdir(tokens[1]) != 0){
        printf("Erro: diretorio '%s' não existe\n", tokens[1]);
        return;
    }

}