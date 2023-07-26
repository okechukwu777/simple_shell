#include "shell.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

void change_directory(char *directory) 
{
	char *prev_dir = getenv("PWD");
	char current_dir[PATH_MAX];
	if (directory == NULL || strcmp(directory, "-") == 0) 
	{
		directory = getenv("OLDPWD");		
		if (directory == NULL) 
		{
			fprintf(stderr, "cd: OLDPWD not set\n");
			return;
		}
		printf("%s\n", directory);
	}
	if (chdir(directory) == -1) 
	{
		perror("chdir");
		return;
	}
	if (getcwd(current_dir, sizeof(current_dir)) == NULL) 
	{
		perror("getcwd");
		return;
	}
	set_environment_variable("PWD", current_dir);
	set_environment_variable("OLDPWD", prev_dir);
}

