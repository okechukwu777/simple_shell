#include "shell.h"
#include <string.h>


Alias *find_alias(char *name) 
{
	static Alias *current_alias = NULL;
	if (name == NULL) 
	{
		Alias *alias = current_alias;
		if (alias != NULL) 
		{
			current_alias = alias->next;
		}
		return alias;
	}
	else 
	{
		Alias *alias = alias_list;
		while (alias != NULL) 
		{
			if (strcmp(alias->name, name) == 0) 
			{
				return alias;
			}
			alias = alias->next;
		}
		return NULL;
	}
}

