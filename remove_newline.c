#include "shell.h"
#include <string.h>

void remove_newline(char *string)
{
	int length = strlen(string);

	if (length > 0 && string[length - 1] == '\n')
	{
		string[length - 1] = '\0';
	}
}

