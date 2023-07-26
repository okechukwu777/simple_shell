#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void execute_commands_from_file(const char *filename) 
{
	char *line = NULL;
        size_t len = 0;
        ssize_t read;
	FILE *file = fopen(filename, "r");
	if (file == NULL) 
	{
		fprintf(stderr, "Error opening file: %s\n", filename);
		return;
	}
	while ((read = getline(&line, &len, file)) != -1) 
	{
		remove_newline(line);
		execute_command(line, NULL);
	}
	fclose(file);
	if (line)
	free(line);
}

