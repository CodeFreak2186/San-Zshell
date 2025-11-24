//
// Created by sans on 11/24/25.
//

#define _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pwd.h>
#include "prompt.h"

char *get_prompt() {
    char cwd[1024];
    if (!getcwd(cwd, sizeof(cwd))) {
        snprintf(cwd, sizeof(cwd), "?");
    }

    const char *user = getenv("USER");
    if (!user) {
        struct passwd *pw = getpwuid(geteuid());
        user = pw ? pw->pw_name : "user";
    }

    /* allocate prompt string (caller will free) */
    size_t needed = snprintf(NULL, 0, "%s:%s$ ", user, cwd) + 1;
    char *prompt = malloc(needed);
    if (!prompt) return NULL;
    snprintf(prompt, needed, "%s:%s$ ", user, cwd);
    return prompt;
}
