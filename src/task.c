#include <stdio.h>
#include <string.h>

#include "../include/task.h"

#define MAX_TASKS 100
#define MAX_LEN_TASK 75
#define MAX_ARGS 10
#define MAX_LEN_ARG 50

typedef struct task{

    char nome[100];
    char path[MAX_LEN_TASK];
    char args[MAX_ARGS][MAX_LEN_ARG];
    int  nun_args;

}task;

task tasks[MAX_TASKS];
int qtd_cadastradas = 0;

void cadastrarTask(char** tokens){

    

    // Caso a quantidade de tarefas cadastradas ultrapasse o limite(add ao relatorio)
    if (qtd_cadastradas >= MAX_TASKS){
        printf("Maximo de tarefas cadastradas");
        return ;
    }

    // Em caso da task já existir ela é sobrescrita com a mais recente 
    for (int i = 0; i < qtd_cadastradas; i++){
        if(0 == strcmp(tokens[1], tasks[i].nome)) {

            strcpy(tasks[i].path, tokens[2]);

            int qtd_args = 0;
            for (int y = 0; y < tasks[i].nun_args; y++){
                strcpy(tasks[i].args[y][y], tokens[3 + y]);
                qtd_args++;
            }

            


            printf("Sobrescrevendo a tarefa antiga de mesmo nome");

        }

    }

    // add nova tarefa

    strcpy(tasks[qtd_cadastradas].nome, tokens[1]);
    strcpy(tasks[qtd_cadastradas].path, tokens[2]);


    while (tokens != NULL)
    {
        size_t len_arg = strlen(tokens[3 + tasks[qtd_cadastradas].nun_args]);
        strcpy(tasks[qtd_cadastradas].args[tasks[3 +]nun_args]);
    }
    




    qtd_cadastradas++;

}





