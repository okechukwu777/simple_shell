#include "shell.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void define_alias(char *name, char *value) 
{
	Alias *alias = find_alias(name);
	if (alias != NULL) 
	{
		free(alias->value);
		alias->value = strdup(value);
	} 
	else 
	{
		Alias *new_alias = (Alias *)malloc(sizeof(Alias));
		new_alias->name = strdup(name);
		new_alias->value = strdup(value);
		new_alias->next = alias_list;
		alias_list = new_alias;
	}
}

