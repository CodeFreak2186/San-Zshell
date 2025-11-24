//
// Created by sans on 11/24/25.
//

#ifndef SAN_Z_SHELL_BUILTINS_H
#define SAN_Z_SHELL_BUILTINS_H


int is_builtin(const char *cmd);
int run_builtin(char **args);

#endif //SAN_Z_SHELL_BUILTINS_H