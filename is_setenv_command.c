#include "shell.h"
#include <string.h>

int is_setenv_command(char *command)
{
    return (strcmp(command, "setenv") == 0);
}

