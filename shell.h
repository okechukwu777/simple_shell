#ifndef SHELL_H
#define SHELL_H

#define MAX_COMMAND_LENGTH 1024

typedef struct Alias {
char *name;
char *value;
struct Alias *next;
} Alias;

extern char **environ;
Alias *alias_list;

void execute_command(char *command, char *args[]);
int is_exit_command(char *command);
int is_env_command(char *command);
void print_environment();
int is_setenv_command(char *command);
int is_unsetenv_command(char *command);
int is_cd_command(char *command);
void set_environment_variable(char *variable, char *value);
void unset_environment_variable(char *variable);
void change_directory(char *directory);
void print_aliases();
Alias *find_alias(char *name);
void define_alias(char *name, char *value);
int is_alias_command(char *command);
void process_alias_command(char *args[]);
void remove_newline(char *string);
void execute_commands_from_file(const char *filename);
void display_prompt();
char *read_command();

#endif /* SHELL_H */

