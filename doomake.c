/*
 * Doomake is a simple <50 line Makefile (like) clone written in C.
 *
 * https://github.com/aiocat/doomake
 *
 * Licensed under MIT License
 * 
 * For more information, please check:
 * https://github.com/aiocat/doomake/blob/main/LICENSE
 * 
 * Copyright (C) 2022, aiocat <aiocat@protonmail.com>
 *
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

// write error to stderr
int write_error(char* msg) { 
    fprintf(stderr, msg); 
    return EXIT_FAILURE; 
}

int main(int argc, char **argv) {
    if (argc < 2) return write_error("Command name must be given!"); // check argument size

    int collect = 0; // collect value
    const char* command = argv[1]; // get first argument
    char line[1025], commandName[256]; // line buffer and command name format
    FILE *filePointer; // file pointer

    filePointer = fopen("Doomake", "r"); // open doomake file in read mode
    if (filePointer == NULL) return write_error("Can't find Doomake file"); // check if file exists

    strcpy(commandName, command);
    strcat(commandName, ":\n");

    while (fgets(line, sizeof(line), filePointer)) { // read line-by-line
        if (collect) { // if collect
            if (strcmp(line, "\n") == 0) break; // stop collecting if new line
            else system(line); // run if not only new line
        } else if (strcmp(line, commandName) == 0) collect = 1; // if command name matches
    }

    fclose(filePointer); // close file
    if (collect == 0) return write_error("Command not found"); // check if collected a command

    return EXIT_SUCCESS;
}