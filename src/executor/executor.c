//
// Created by sans on 11/24/25.
//

#define _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "executor.h"

/* Execute external command via fork + execvp + waitpid */
void execute_command(char **args) {
    pid_t pid = fork();
    if (pid < 0) {
        perror("fork");
        return;
    }

    if (pid == 0) {
        /* Child: restore default signals if needed, then exec */
        execvp(args[0], args);
        /* If execvp returns, it's an error */
        perror(args[0]);
        _exit(127);
    } else {

        /* Parent: wait for child */
        int status = 0;
        if (waitpid(pid, &status, 0) == -1) {
            perror("waitpid");
            return;
        }
        /* Optionally: you can inspect status here */
    }
}
