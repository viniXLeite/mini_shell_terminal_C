#include <stdio.h>
#include <stdlib.h>
#include "queue.h"
#include <string.h>
#include <unistd.h>
#include <stdbool.h>
#include <ctype.h>
#include <dirent.h>
#include "../include/builtins.h"

#ifndef __EXECUTOR__
#define __EXECUTOR__

#define unix_path_limit 4096


bool executor(queue_t* tokens_queue) {
    char* command = (char*) tokens_queue->data;

    if (strcmp((char*) tokens_queue->data, "exit") == 0) return false;
    else if (strcmp(command, "clr") == 0) clr();
    else if (strcmp(command, "echo") == 0) echo(tokens_queue); // exibir os outros argumentos tbm
    else if (strcmp(command, "pwd") == 0) pwd();
    else if (strcmp(command, "ls") == 0 || strcmp(command, "l") == 0) show_dr(); // argumento -l e -a
    else if (strcmp(command, "cd") == 0) cd(tokens_queue);
    else if (strcmp(command, "touch") == 0) touch(tokens_queue);
    else if (strcmp(command, "cat") == 0) cat_file(tokens_queue);
    else if (strcmp(command, "help") == 0) help_file();
    else command_not_found(tokens_queue);

    return true; 
}



#endif

