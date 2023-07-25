#include "shell.h"
#include <stdio.h>


void print_aliases() 
{
	Alias *alias = find_alias(NULL);
	
	while (alias != NULL)
	{
		printf("%s='%s'\n", alias->name, alias->value);
		alias = find_alias(NULL);
	}
}

