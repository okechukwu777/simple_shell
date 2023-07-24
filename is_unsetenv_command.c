#include "shell.h"
#include <string.h>

int is_unsetenv_command(char *command)
{
    return (strcmp(command, "unsetenv") == 0);
}

