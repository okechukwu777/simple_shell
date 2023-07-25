#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void process_alias_command(char *args[]) 
{
	if (args[1] == NULL) 
	{
		print_aliases();
	} 
	else 
	{
		int arg_index = 1;
		while (args[arg_index] != NULL) 
		{
			char *arg = args[arg_index];
			char *equal_sign = strchr(arg, '=');
			if (equal_sign != NULL) 
			{
				*equal_sign = '\0';
				define_alias(arg, equal_sign + 1);
			} 
			else 
			{
				Alias *alias = find_alias(arg);
				if (alias != NULL) 
				{
					printf("%s='%s'\n", alias->name, alias->value);
				} 
				else 
				{
					fprintf(stderr, "alias: %s: not found\n", arg);
				}
			}
			arg_index++;
		}
	}
}

