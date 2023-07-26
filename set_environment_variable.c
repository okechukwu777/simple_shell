#include "shell.h"
#include <stdlib.h>
#include <stdio.h>

void set_environment_variable(char *variable, char *value)
{
	if (setenv(variable, value, 1) != 0)
	{
	perror("setenv");
	}
}

