#include "shell.h"
#include <string.h>

int is_exit_command(char *command)
{
	return (strcmp(command, "exit") == 0);
}

