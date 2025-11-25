#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void print_banner() {
    srand(time(NULL)); // seed RNG
    int colorIndex = rand() % 7; // pick 0–6

    const char* colors[] = {
        "\033[1;31m", // red
        "\033[1;32m", // green
        "\033[1;33m", // yellow
        "\033[1;34m", // blue
        "\033[1;35m", // magenta
        "\033[1;36m", // cyan
    };

    const char* color = colors[colorIndex];

    printf("%s", color);  // SET RANDOM COLOR

    // ---- BIG SAN–ZSHL BANNER ----
    printf("   ███████╗ █████╗ ███╗   ██╗       ███████╗  ██████╗  ██╗  ██╗ ██╗      \n");
    printf("   ██╔════╝██╔══██╗████╗  ██║       ╚══███╔╝  ██╔═══╝  ██║  ██║ ██║      \n");
    printf("   ███████╗███████║██╔██╗ ██║         ███╔╝   ██████╗  ███████║ ██║      \n");
    printf("   ╚════██║██╔══██║██║╚██╗██║        ███╔╝    ╚═══██║  ██╔══██║ ██║      \n");
    printf("   ███████║██║  ██║██║ ╚████║       ███████╗  ██████║  ██║  ██║ ███████╗ \n");
    printf("   ╚══════╝╚═╝  ╚═╝╚═╝  ╚═══╝       ╚══════╝  ╚═════╝  ╚═╝  ╚═╝ ╚══════╝ \n");

    printf("\033[1;35m");
    printf("                      •  S A N – Z S H L  •\n");

    printf("\033[1;37m");
    printf("                  (•_•)  Welcome to San-ZShell  (•_•)\n");
    printf("            A lightweight, modular, fast C-based shell.\n");
    printf("\033[0m"); // RESET COLOR
}
