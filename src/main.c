#include <stdio.h>
#include <string.h>

#include "../include/parcer.h"
#include "../include/task.h"
#include "../include/run.h"




int main(int argc, char *argv[]){

    // modo workflow
    if(argc > 1){

    }else if(argc == 1){  // modo interativo
        while(1){

            printf("ProcessFlow> ");
            char** tokens = parcer_line();

            if(tokens == NULL){
                printf("Error de leitura");
                continue;
            }
            // cadastra nova task
            if(strcmp(tokens[0], "task") == 0) {
                cadastrarTask(tokens);
            }

            //execulta uma task
            if(strcmp(tokens[0], "run") == 0) {
                run(tokens);
            }
            /** 
            for(int i = 0; tokens[i] != NULL; i++){
                printf("token[%d] = \"%s\"\n", i, tokens[i]);      
            }
            */

            if(strcmp(tokens[0], "exit") == 0){
                free_tokens(tokens);
                break;
            }

            free_tokens(tokens);

        }   

    }

    return 0;
}