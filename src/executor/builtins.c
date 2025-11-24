//
// Created by sans on 11/24/25.
//

#define _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

#include "builtins.h"

int is_builtin(const char *cmd) {
    if (!cmd) return 0;
    return (strcmp(cmd, "cd") == 0) || (strcmp(cmd, "exit") == 0);
}

int run_builtin(char **args) {
    if (!args || !args[0]) return 0;

    if (strcmp(args[0], "cd") == 0) {
        char *dir = args[1];
        if (!dir) dir = getenv("HOME");
        if (!dir) dir = "/";
        if (chdir(dir) != 0) {
            perror("cd");
        }
        return 1;
    }

    if (strcmp(args[0], "exit") == 0) {
        /* optional: free other resources here */
        exit(0);
    }

    return 0;
}
