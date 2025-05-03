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
    queue_t* node = (queue_t*) malloc(sizeof(queue_t));

    if (token == NULL) {
        char *data = strdup(" ");

        node->data = data;
        node->prev = NULL;
        node->next = NULL;
    
        return node;
    }
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
        printf("TOKEN NULL\n");
    }

    queue_t* node = createNode(token);

    printf("ok2\n");

    while (token != NULL) {
        // Adds the token to a queue
        node = createNode(token);
        queue_append(&head, node);
        
        // Extracts the next token
        token = strtok(NULL, " ");
    }

    printf("q sze: %d\n", queue_size(head));
    free(token);

    return head;
}



int main() {
    char buffer[256];

    // check if username is NULL
    char *username = getenv("USER");  // Ou "LOGNAME" em alguns sistemas 
    char current_path[unix_path_limit];

    // LEMBRAR DE RETIRARA os \n

    while (1) {
        getcwd(current_path, sizeof(current_path));
        printf(RED "%s" RESET ":" GRN "~%s" RESET WHT "& " RESET, username, current_path);
        
        // Stores the user's input
        if (fgets(buffer, sizeof(buffer), stdin) == NULL) continue;

        // Switches the '\n' character to '\0'
        buffer[strcspn(buffer, "\n")] = '\0';

        printf("%ld\n", strlen(buffer));

        size_t buffer_len = strlen(buffer);
        char* tokens = malloc(buffer_len);

        // Checks if the string used to store the buffer is NULL and has len greater than 0
        if (tokens != NULL && buffer_len > 0) {
            strcpy(tokens, buffer);
        }
        else continue;
        printf("ok1\n");

        // Gets the commands list
        queue_t* command_list = parse_commands(tokens);
        
        if(queue_size(command_list) == 0) continue;

        char* command = (char*) command_list->data;

        // exit command
        if (strcmp(tokens, "exit") == 0) break;
        else if (strcmp(tokens, "clr") == 0) system("clear");
        else printf("vish :: '%s' Command not found\n", (char*) command);

        free(tokens);
        free(command_list);
    }
    
    return 0;
}