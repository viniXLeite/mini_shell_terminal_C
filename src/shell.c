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


int main() {

    
    
    char current_path[unix_path_limit];
    // Could not acess path
    if (!getcwd(current_path, sizeof(current_path))) {
        perror("Vish: Could update path");
    }

    char* help_txt_path = malloc(unix_path_limit);
    // Copies the token_list->next content to file_name
    snprintf(help_txt_path, unix_path_limit, "%s/help.txt", current_path);




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
        if (executor(tokens_list, help_txt_path) == false) break;

        free(tokens);
        free(tokens_list);
    }
    
    return 0;
}
