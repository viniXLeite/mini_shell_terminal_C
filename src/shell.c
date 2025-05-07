#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>
#include <dirent.h>
#include <stdbool.h>

#include "../include/queue.h"
#include "../include/parser.h"
#include "../include/prompt.h"
#include "../include/executor.h"

/*
READ
EVAL
PRINT
LOOP
*/

// Transformar esse arquivo em main.c e colocar o conteudo em uma função 'main_loop' em shell.h

/*
EXPANDER: Feito os tokens, o expander rodava eles em busca do '$' e das aspas para a expansão das variáveis 
de ambiente e remoção das aspas. Caso o expander encontrasse a variável descrida depois do símbulo ($), 
ele a substituia pelo seu valor (guardado na nossa variável envp), caso contrário, substituia pur vazio ("").
 Já as aspas, seguindo algumas regras, eram removidas do token.
*/


int main() {
    system("clear");

    char buffer[256];
    char* home = getenv("HOME");

    if (chdir(home) != 0) {  // Switches to Home directory
        perror("Vish: could not acess Home directory");
        return 1;
    }


    while (1) {
        show_command_prompt();

        // Stores the user's input
        if(!fgets(buffer, sizeof(buffer), stdin)) {
            perror("Vish: Could not store user's input");
        }

        // Switches the '\n' character to '\0'
        buffer[strcspn(buffer, "\n")] = '\0';
        //printf("buffer len: %ld\n", strlen(buffer));    

        size_t buffer_len = strlen(buffer);
        char* tokens = malloc(buffer_len);

        // Checks if the string used to store the buffer is NULL
        if (tokens == NULL) continue;
        else strcpy(tokens, buffer);

        // Gets the commands list
        queue_t* tokens_list = parse_commands(tokens);

        // Checks if the command list is NULL
        if(tokens_list == NULL) continue;

        // Executes the Shell commands
        // BUILTINS
        if (executor(tokens_list) == false) break;

        // Codigo para criar variavel pode ser 'var' 'type' 'value'

        free(tokens);
        free(tokens_list);
    }
    
    return 0;
}
