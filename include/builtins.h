#include <stdio.h>
#include <stdlib.h>
#include "queue.h"
#include <string.h>
#include <unistd.h>
#include <stdbool.h>
#include <ctype.h>
#include <dirent.h>


#ifndef __BUILTINS__
#define __BUILTINS__

#define unix_path_limit 4096

void touch(queue_t* tokens_queue) {
            
    size_t buffer_len = strlen((char*)tokens_queue->next->data)+1; // +1 because of the termination character '\0'
    char* file_name = malloc(buffer_len);

    // Copies the token_list->next content to file_name
    snprintf(file_name, buffer_len, "%s", (char*)tokens_queue->next->data ? (char*)tokens_queue->next->data : "(ERROR)");
    
    // Couldnt allocate file_name
    if (file_name == NULL) {
        perror("Vish: Allocation error");
        free(file_name);
    }

    FILE* file = fopen(file_name, "a");

    // Couldnt open the file
    if (file == NULL) {
        perror("Vish: File creation error");
        free(file_name);
    }
    fclose(file);
    free(file_name);
}


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
  
    while ((de = readdir(dr)) != NULL) 
            printf("%s\n", de->d_name); 
  
    closedir(dr);     
}

bool exit_loop() {
    return true;
}

void clr() {
    system("clear");
    return;
}

void echo(queue_t* tokens_queue) {
    queue_t* current = tokens_queue->next;
    
    // Print all the words input by the user
    while (current != tokens_queue) {
        printf("%s ", (char*) current->data);
        current = current->next;
    }

    printf("\n");
    return;
}

void pwd() {
    char current_path[unix_path_limit];

    // Could not acess path
    if (!getcwd(current_path, sizeof(current_path))) {
        perror("Vish: Could update path");
    }
    
    printf("%s\n", (char*) current_path);
    return;
}

void cd(queue_t* tokens_queue) {
    char* path = (char*) tokens_queue->next->data;

    // returns to the HOME directory
    if (tokens_queue->next == tokens_queue) {
        if (chdir(getenv("HOME")) != 0) {
            perror("Vish: could not acess Home directory");    
        }

    }
    // Could not find the directory
    else if (chdir(path) != 0) {
        printf("Vish: cd: No directory called %s\n", path);
    }
}


void command_not_found(queue_t* tokens_queue) {
    printf("vish :: '%s' Command not found\n", (char*) tokens_queue->data);
    return;
}

void cat_file(queue_t* tokens_queue) {
    size_t buffer_len = strlen((char*) tokens_queue->next->data)+1;
    char* file_name = malloc(buffer_len);
    strcpy(file_name, (char*) tokens_queue->next->data);

    if (file_name == NULL) {
        perror("Vish: Allocation error");
        free(file_name);
        return;
    }

    char line[4096];
    FILE* file = fopen(file_name, "r");

    if (file == NULL) {
        perror("Vish: Could not open file");
        free(file_name);
        return;
    }

    // prints the content of the file
    while (fgets(line, sizeof(line), file)) {
        printf("%s", line);
    }
    
    fclose(file);
    return;
}

void help_file() {
    char line[4096];
    FILE* file = fopen("/home/vinic/dev/c/mini_shell_terminal_C/include/help.txt", "r");

    if (file == NULL) {
        perror("Vish: Could not open HELP file");
        return;
    }

    // prints the content of the file
    while (fgets(line, sizeof(line), file)) {
        printf("%s", line);
    }
    
    printf("\n");
    fclose(file);
    return;
}

#endif

