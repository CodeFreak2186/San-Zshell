cmake_minimum_required(VERSION 3.16)
project(San_Z_shell C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra -g")

include_directories(include)

file(GLOB CORE_SOURCES "src/core/*.c")
file(GLOB EXEC_SOURCES "src/executor/*.c")

add_executable(San_Z_shell ${CORE_SOURCES} ${EXEC_SOURCES}
        include/prompt.h
        include/repl.h
        include/executor.h
        include/builtins.h
        src/core/prompt.c
        src/core/repl.c
        src/executor/executor.c
        src/executor/builtins.c)
