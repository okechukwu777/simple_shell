#include "shell.h"
#include <stdio.h>

/**
 * print_aliases - function that prints alias
 *
 */

void print_aliases(void)
{
	Alias *alias = find_alias(NULL);

	while (alias != NULL)
	{
		printf("%s='%s'\n", alias->name, alias->value);
		alias = find_alias(NULL);
	}
}

