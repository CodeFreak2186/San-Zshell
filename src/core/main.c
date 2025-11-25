//
// Created by sans on 11/24/25.
//

#include <stdio.h>
#include "repl.h"
#include "banner.h"


int main(void) {
    print_banner();
    repl_loop();
    return 0;
}
