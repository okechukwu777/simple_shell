#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

void execute_command(char *command, char *args[])
{
	if (is_exit_command(command))
	{
		exit(0);
	}
	else if (is_env_command(command))
	{
		print_environment();
	}
	else if (is_setenv_command(command))
	{
	if (args[1] != NULL && args[2] != NULL)
	{
	set_environment_variable(args[1], args[2]);
	}
	Else
	{
	fprintf(stderr, "setenv: Invalid arguments\n");
	}
	}
	else if (is_unsetenv_command(command))
	{
	if (args[1] != NULL)
	{
	unset_environment_variable(args[1]);
	}
	Else
	{
	fprintf(stderr, "unsetenv: Invalid arguments\n");
	}
	}
	else if (is_cd_command(command))
	{
	if (args[1] != NULL)
	{
	change_directory(args[1]);
	}
	Else
	{
	change_directory("$HOME");
	}
	}
	else if (is_alias_command(command))
	{
	process_alias_command(args);
	}
	else
	{
	pid_t child_pid = fork();
	if (child_pid == -1)
	{
	perror("fork");
	}
	else if (child_pid == 0)
	{
	if (execvp(command, args) == -1)
	{
	perror("execvp");
	_exit(EXIT_FAILURE);
	}
	}
	Else
	{
	int status;
	if (waitpid(child_pid, &status, 0) == -1)
	{
	perror("waitpid");
	}
	}
	}
}

