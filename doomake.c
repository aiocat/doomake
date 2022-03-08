#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char** argv) {
    if (argc < 2) { // check argument size
        puts("Command name must be given!");
        return 1;
    }

    char* command = argv[1]; // get first argument
    puts(command);
}