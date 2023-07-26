#include "shell.h"
#include <stdio.h>

void print_environment(void)
{
	char **env = environ;

	while (*env)
	{
	printf("%s\n", *env);
	env++;
	}
}

