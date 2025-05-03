#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "../include/queue.h"

// Defines the terminal's text colors
#define RED   "\x1B[31m"
#define GRN   "\x1B[32m"
#define YEL   "\x1B[33m"
#define BLU   "\x1B[34m"
#define MAG   "\x1B[35m"
#define CYN   "\x1B[36m"
#define WHT   "\x1B[37m"
#define RESET "\x1B[0m"

#define unix_path_limit 4096

/*
READ
EVAL
PRINT
LOOP
*/

queue_t* createNode(char* token) {
    // Checks if the token is valid
    if(token == NULL) return NULL;
    
    queue_t* node = (queue_t*) malloc(sizeof(queue_t));

    // Allocates a space for 'data' pointer and copies token into it
    char *data = strdup(token);

    node->data = data;
    node->prev = NULL;
    node->next = NULL;

    return node;
}


queue_t* parse_commands(char* tokens) {
    queue_t *head = NULL;

    // Extract the first token of 'tokens'
    char* token = strtok(tokens, " ");

    if (token == NULL) {
        //printf("TOKEN NULL\n");
    }

    queue_t* node = createNode(token);

    while (token != NULL) {
        // Adds the token to a queue
        node = createNode(token);
        queue_append(&head, node);
        
        // Extracts the next token
        token = strtok(NULL, " ");
    }

    //printf("queue sze: %d\n", queue_size(head));
    free(token);

    return head;
}

void show_command_prompt() {
    // Gets username from the operating system
    char *username = getenv("USER"); 
    char current_path[unix_path_limit];

    // Gets the current path
    getcwd(current_path, sizeof(current_path));
    
    // checks if username and current path are NULL
    if (username != NULL && current_path != NULL) {
        printf(RED "%s" RESET ":" GRN "~%s" RESET WHT "& " RESET, username, current_path);
    }
    else {
        printf(RED "username" RESET ":" GRN "~path" RESET WHT "& " RESET);
    }
}


int main() {
    char buffer[256];

    while (1) {
        show_command_prompt();

        // Stores the user's input
        fgets(buffer, sizeof(buffer), stdin);
        // Switches the '\n' character to '\0'
        buffer[strcspn(buffer, "\n")] = '\0';
        //printf("buffer len: %ld\n", strlen(buffer));    

        size_t buffer_len = strlen(buffer);
        char* tokens = malloc(buffer_len);

        // Checks if the string used to store the buffer is NULL
        if (tokens == NULL) continue;
        else strcpy(tokens, buffer);

        //printf("ok create token\n");

        // Gets the commands list
        queue_t* tokens_list = parse_commands(tokens);
        
        // Checks if the command list is NULL
        if(tokens_list == NULL) continue;
        char* command = (char*) tokens_list->data;

        // Executes the Shell commands
        if (strcmp(tokens, "exit") == 0) break;
        else if (strcmp(tokens, "clr") == 0) system("clear");
        else printf("vish :: '%s' Command not found\n", (char*) command);

        free(tokens);
        free(tokens_list);
    }
    
    return 0;
}