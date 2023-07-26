#include "shell.h"
#include <stdlib.h>
#include <stdio.h>
void unset_environment_variable(char *variable)
{
	if (unsetenv(variable) != 0)
	{
		perror("unsetenv");
	}
}

