#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char **argv)
{
    if (argc < 2) { // check argument size
        puts("Command name must be given!");
        return EXIT_FAILURE;
    }

    const char *command = argv[1]; // get first argument

    FILE *filePointer;
    char line[1025];

    filePointer = fopen("Doomake", "r"); // open doomake file in read mode
    if (filePointer == NULL) { // check if file exists
        puts("Can't find Doomake file");
        return EXIT_FAILURE;
    }

    char commandName[256]; // command name format
    strcpy(commandName, command);
    strcat(commandName, ":\n");

    int collect = 0; // collect value

    while (fgets(line, sizeof(line), filePointer)) // read line-by-line
    {
        if (collect) // if collect
        {
            if (strcmp(line, "\n") == 0) break; // stop collecting if new line
            else system(line); // run if not only new line
        }
        else {
            if (strcmp(line, commandName) == 0) collect = 1; // if command name matches
        }
    }

    fclose(filePointer); // close file

    if (collect == 0) { // check if collected a command
        puts("Command not found");
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}