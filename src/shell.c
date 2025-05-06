#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>
#include <dirent.h>

#include "../include/queue.h"
#include "../include/parser.h"
#include "../include/prompt.h"

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

void show_dr() {
    // ADD -a and -r flags

    struct dirent *de;  // Pointer for directory entry 
    

    // opendir() returns a pointer of DIR type.  
    DIR *dr = opendir("."); 
  
    if (dr == NULL)  // opendir returns NULL if couldn't open directory 
    { 
        printf("Could not open current directory" ); 
        return; 
    } 
  
    // Refer http://pubs.opengroup.org/onlinepubs/7990989775/xsh/readdir.html 
    // for readdir() 
    while ((de = readdir(dr)) != NULL) 
            printf("%s\n", de->d_name); 
  
    closedir(dr);     
}


int main() {
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
        char* command = (char*) tokens_list->data;

        char current_path[unix_path_limit];
        if (!getcwd(current_path, sizeof(current_path))) {
            perror("Vish: Could update path");
            break;
        }

        // Executes the Shell commands
        // BUILTINS
        if (strcmp(command, "exit") == 0) break; 
        else if (strcmp(command, "clr") == 0) system("clear");
        else if (strcmp(command, "echo") == 0) printf("%s\n", (char*) tokens_list->next->data); // exibir os outros argumentos tbm
        else if (strcmp(command, "pwd") == 0) printf("%s\n", (char*) current_path);
        else if (strcmp(command, "ls") == 0 || strcmp(command, "l") == 0) show_dr(); // argumento -l e -a

        else if (strcmp(command, "cd") == 0) {

            char* path = (char*) tokens_list->next->data;

            if (tokens_list->next == tokens_list) {
                if (chdir(getenv("HOME")) != 0) {
                    perror("Vish: could not acess Home directory");    
                }
    
            }
            else if (chdir(path) != 0) {
                printf("Vish: cd: No directory called %s\n", path);
            }

        } // argumento -l e -a
        
        else if (strcmp(command, "touch") == 0) {
            
            size_t buffer_len = strlen((char*)tokens_list->next->data)+1; // +1 because of the termination character '\0'
            char* file_name = malloc(buffer_len);

            // Copies the token_list->next content to file_name
            snprintf(file_name, buffer_len, "%s", (char*)tokens_list->next->data ? (char*)tokens_list->next->data : "(ERROR)");
            
            // Couldnt allocate file_name
            if (file_name == NULL) {
                perror("Allocation error");
                free(file_name);
                continue;
            }

            FILE* file = fopen(file_name, "a");

            // Couldnt open the file
            if (file == NULL) {
                perror("File creation error");
                free(file_name);
                continue;
            }
            fclose(file);
            free(file_name);
        }

        else printf("vish :: '%s' Command not found\n", (char*) command);
        // Codigo para criar variavel pode ser 'var' 'type' 'value'


        free(tokens);
        free(tokens_list);
    }
    
    return 0;
}