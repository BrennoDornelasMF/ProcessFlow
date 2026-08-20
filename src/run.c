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
