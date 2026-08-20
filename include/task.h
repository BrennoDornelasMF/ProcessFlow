#ifndef TASK_H
#define TASK_H

#define MAX_TASKS 100
#define MAX_LEN_TASK 75
#define MAX_ARGS 10
#define MAX_LEN_ARG 50

typedef struct task{
    char nome[100];
    char path[MAX_LEN_TASK];
    char args[MAX_ARGS][MAX_LEN_ARG];
    int  nun_args;
} task;

extern task tasks[MAX_TASKS];
extern int qtd_cadastradas;

void cadastrarTask(char** tokens);
task* buscarTask(char* nome);

#endif