#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#ifndef __PROMPT__
#define __PROMPTs__

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
    // Invalid path case
    else if (username != NULL) {
        printf(RED "%s" RESET ":" GRN "~path" RESET WHT "& " RESET, username);
    }    
    // Invalid username case
    else if (current_path != NULL) {
        printf(RED "username" RESET ":" GRN "~%s" RESET WHT "& " RESET, username);
    }
    else {
        printf(RED "username" RESET ":" GRN "~path" RESET WHT "& " RESET);
    }

}


#endif

