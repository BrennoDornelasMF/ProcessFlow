#include <stdio.h>
#include <string.h>

#include "../include/task.h"


task tasks[MAX_TASKS];
int qtd_cadastradas = 0;

void cadastrarTask(char** tokens){

    // valida que a frase tenha nome e programa
    if (tokens[1] == NULL || tokens[2] == NULL){
        printf("Error: o comando task precisa de nome e programa\n");
        return;
    }

    // Caso a quantidade de tarefas cadastradas ultrapasse o limite(add ao relatorio)
    if (qtd_cadastradas >= MAX_TASKS){
        printf("Maximo de tarefas cadastradas\n");
        return ;
    }

    // Em caso da task já existir ela é sobrescrita com a mais recente 
    for (int i = 0; i < qtd_cadastradas; i++){
        if(strcmp(tokens[1], tasks[i].nome) == 0) {

            strcpy(tasks[i].path, tokens[2]);

            int qtd_args = 0;
            while(tokens[3 + qtd_args] != NULL && qtd_args < MAX_ARGS){
                strcpy(tasks[i].args[qtd_args], tokens[3 + qtd_args]);
                qtd_args++;
            }

            printf("Sobrescrevendo a tarefa antiga de mesmo nome/n");

            return;
        }
    }

    // add nova tarefa

    strcpy(tasks[qtd_cadastradas].nome, tokens[1]);
    strcpy(tasks[qtd_cadastradas].path, tokens[2]);

    int qtd_args = 0;
    while (tokens[3 + qtd_args] != NULL && qtd_args < MAX_ARGS){
        strcpy(tasks[qtd_cadastradas].args[qtd_args], tokens[3 + qtd_args]);
        qtd_args++;        
    }
    tasks[qtd_cadastradas].nun_args = qtd_args;
    strcpy(tasks[qtd_cadastradas].input_file, "");
    strcpy(tasks[qtd_cadastradas].output_file, "");
    tasks[qtd_cadastradas].append_mode = 0;
    
    qtd_cadastradas++;
    //printf("Task adicionada com sucesso\n");

}

task* buscarTask(char* nome){
    for (int i = 0; i < qtd_cadastradas; i++){
        if (strcmp(tasks[i].nome, nome) == 0){
            return &tasks[i];
        }
    }
    return NULL;
}
