#include "shell.h"
#include <string.h>

int is_cd_command(char *command)
{
    return (strcmp(command, "cd") == 0);
}

