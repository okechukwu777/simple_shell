#include "shell.h"
#include <string.h>

int is_alias_command(char *command) 
{
	return (strcmp(command, "alias") == 0);
}

