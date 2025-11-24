//
// Created by sans on 11/24/25.
//
#define _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "prompt.h"
#include "executor.h"
#include "builtins.h"

#define MAX_TOKENS 128

void repl_loop() {
    char *line = NULL;
    size_t len = 0;

    while (1) {
        char *prompt = get_prompt();
        printf("[my_shell]> ");
        if (!prompt) prompt = strdup("> ");

        printf("%s", prompt);
        fflush(stdout);
        free(prompt);

        ssize_t nread = getline(&line, &len, stdin);
        if (nread == -1) { /* EOF or error */
            printf("\n");
            break;
        }

        /* remove trailing newline */
        if (nread > 0 && line[nread-1] == '\n') line[nread-1] = '\0';

        /* basic trimming: skip empty lines */
        char *s = line;
        while (*s && (*s == ' ' || *s == '\t')) s++;
        if (*s == '\0') continue;

        /* Tokenize on whitespace (simple) */
        char *tokens[MAX_TOKENS];
        int i = 0;
        char *tok = strtok(line, " \t");
        while (tok && i < MAX_TOKENS - 1) {
            tokens[i++] = tok;
            tok = strtok(NULL, " \t");
        }
        tokens[i] = NULL;

        if (tokens[0] == NULL) continue;

        /* builtin handling */
        if (is_builtin(tokens[0])) {
            run_builtin(tokens);
            continue;
        }

        /* external command */
        execute_command(tokens);
    }

    free(line);
}
