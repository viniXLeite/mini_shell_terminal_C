#include <stdio.h>
#include <stdlib.h>
#include "queue.h"
#include <string.h>
#include <unistd.h>
#include <stdbool.h>
#include <ctype.h>


#ifndef __PARSER__
#define __PARSER__

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


queue_t* parse_commands(const char *input) {
    queue_t* head = NULL;
    queue_t* node = head;

    int i = 0, j = 0;
    bool in_quotes = false;
    char buffer[256];

    while (*input) {

        // Case where the character analised is a quote 
        if (*input == '"') {
            in_quotes = !in_quotes;  
            input++;
            continue;
        }

        if (!in_quotes && isspace(*input)) {
            // End of a word
            if (j > 0) {
                buffer[j] = '\0';
                
                node = createNode(strdup(buffer));
                queue_append(&head, node);
                //printf("token: %s\n", buffer);

                j = 0;
            }
        } else {
            buffer[j++] = *input;
        }
        input++;
    }

    // Last token
    if (j > 0) {
        buffer[j] = '\0';

        node = createNode(strdup(buffer));
        queue_append(&head, node);
        //printf("token: %s\n", buffer);
    }

    //printf("queue size: %d\n", queue_size(head));

    return head;
}


#endif

