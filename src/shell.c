#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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

/*
READ
EVAL
PRINT
LOOP
*/

queue_t* createNode(char* token) {
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
    queue_t* node = createNode(token);

    while (token != NULL) {
        printf("%s\n", token);

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

    // LEMBRAR DE RETIRARA os \n

    while (1) {
        printf(RED "user" RESET ":" BLU "~path" RESET WHT "& " RESET);
        
        // Stores the user's input
        fgets(buffer, sizeof(buffer), stdin);
        size_t buffer_len = strlen(buffer);
        char* tokens = malloc(buffer_len);

        // Checks if the string used to store the buffer is NULL
        if (tokens != NULL) {
            strcpy(tokens, buffer);
        }
        else break;

        // exit command
        if (strcmp(tokens, "exit\n") == 0) break;
        
        queue_t* commands_head = parse_commands(tokens);
        char* data = (char*) commands_head->next->data;
        
        printf("f2: %s\n", data);



        free(tokens);
        free(data);
        free(commands_head);
    }
    
    return 0;
}