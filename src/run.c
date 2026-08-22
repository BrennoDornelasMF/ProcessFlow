#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#include "../include/run.h"

int execultarTaskSincrono(task *t){


    if (t == NULL){
        printf("Erro: tarefa não encontrada\n");
        return 0;
    }

    // construindo a lista com o path + args com NULL ao final para usar o exec()
    char *exec_args[MAX_ARGS + 2];
    exec_args[0] = t->path;

    for (int i = 0;i < t->nun_args; i++){

        exec_args[i + 1] = t->args[i];

    }
    exec_args[t->nun_args + 1] = NULL;

    pid_t pid = fork();

    if (pid < 0){
        printf("Erro ao criar processo\n");
        return 0;
    }

    if (pid == 0){
        execv(t->path, exec_args);
        printf("Erro: não foi possivel executar o programa '%s'\n", t->path);
        _exit(1);
    }else{
        int status;
        waitpid(pid, &status, 0);
        return 1;
    }
}

void run(char** tokens){

    if(tokens[1] == NULL){
        printf("Erro: run precisa de um nome de tarefa\n");
        return;
    }

    // sequencial
    if(strcmp(tokens[1], "sequential") == 0){
        for (int i = 2; tokens[i] != NULL; i++){
            task *t = buscarTask(tokens[i]);
            execultarTaskSincrono(t);
        }
        return;
    }

    // Paralelo
    if (strcmp(tokens[1], "parallel") == 0){
        pid_t pids[MAX_ARGS];
        int total = 0;

        for (int i = 2; tokens[i] != NULL && total < MAX_ARGS; i++){
            task *t = buscarTask(tokens[i]);
            if (t == NULL){
                printf("Erro: tarefa '%s' não encontrada\n", tokens[i]);
                continue;
            }

            char *exec_args[MAX_ARGS + 2];
            exec_args[0] = t->path;

            for (int j = 0; j < t->nun_args;j++){
                exec_args[j + 1] = t->args[j];
            }
            exec_args[t->nun_args + 1] = NULL;

            pid_t pid = fork();
            if (pid == 0){
                execv(t->path, exec_args);
                printf("Erro: não foi possivel execultar '%s'\n", t->path);
                _exit(1);
            } else if(pid > 0){
                pids[total] = pid;
                total++;
            }
        }

        for (int i = 0; i < total;i++){
            int status;
            waitpid(pids[i], &status, 0);
        }
        return;

    }
    task *t = buscarTask(tokens[1]);
    execultarTaskSincrono(t);
}


void input(char** tokens){

    if(tokens[1] == NULL || tokens[2] == NULL){
        printf("Erro: input precisa de tarefa e arquivo");
        return;
    }

    task *t = buscarTask(tokens[1]);

    if (t == NULL){
        printf("Erro tarefa não enotrada");
        return;
    }
    
    strcpy(t->input_file, tokens[2]);
}

void output(char** tokens){

    if(tokens[1] == NULL || tokens[2] == NULL){
        printf("Erro: output precisa de tarefa e arquivo");
        return;
    } 

    task *t = buscarTask(tokens[1]);

    if(t == NULL){
        printf("Erro: Tarefa não encontrada");
        return;
    }

    strcpy(t->output_file, tokens[2]);
    t->append_mode = 0;
}

void append(char** tokens){

    if(tokens[1] == NULL || tokens[2] == NULL){
        printf("Erro: output precisa de tarefa e arquivo");
        return;
    } 

    task *t = buscarTask(tokens[1]);

    if(t == NULL){
        printf("Erro: Tarefa não encontrada");
        return;
    }

    strcpy(t->output_file, tokens[2]);
    t->append_mode = 1;
}
