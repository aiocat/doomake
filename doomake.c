#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char **argv)
{
    if (argc < 2)
    { // check argument size
        puts("Command name must be given!");
        return EXIT_FAILURE;
    }

    const char *command = argv[1]; // get first argument

    FILE *filePointer;
    char line[256];

    filePointer = fopen("Doomake", "r"); // open doomake file in read mode
    if (filePointer == NULL)
    { // check if file exists
        puts("Can't find Doomake file");
        exit(EXIT_FAILURE);
    }

    char commandName[256]; // command name format
    strcpy(commandName, command);
    strcat(commandName, ":\n");

    while (fgets(line, sizeof(line), filePointer))
    {
        if (strcmp(line, commandName) == 0)
        {
            puts("Got it!");
        }

    }

    fclose(filePointer);
    return EXIT_SUCCESS;
}