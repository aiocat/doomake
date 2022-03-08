#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

// write error to stderr
int write_error(char* msg) {
    fprintf(stderr, msg);
    return EXIT_FAILURE;
}

int main(int argc, char **argv)
{
    if (argc < 2) { // check argument size
        return write_error("Command name must be given!");
    }

    const char *command = argv[1]; // get first argument
    FILE *filePointer; // file pointer
    char line[1025]; // line buffer

    filePointer = fopen("Doomake", "r"); // open doomake file in read mode
    if (filePointer == NULL) { // check if file exists
        return write_error("Can't find Doomake file");
    }

    char commandName[256]; // command name format
    int collect = 0; // collect value

    strcpy(commandName, command);
    strcat(commandName, ":\n");

    while (fgets(line, sizeof(line), filePointer)) // read line-by-line
    {
        if (collect) // if collect
        {
            if (strcmp(line, "\n") == 0) break; // stop collecting if new line
            else system(line); // run if not only new line
        }
        else if (strcmp(line, commandName) == 0) collect = 1; // if command name matches
    }

    fclose(filePointer); // close file
    if (collect == 0) { // check if collected a command
        return write_error("Command not found");
    }

    return EXIT_SUCCESS;
}