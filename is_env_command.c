#include "shell.h"
#include <string.h>

int is_env_command(char *command)
{
return (strcmp(command, "env") == 0);
}

