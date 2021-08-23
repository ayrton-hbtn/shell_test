#include "shell.h"

char *builtin_str[] = {
	"cd",
	"help",
	"exit"
};

int (*builtins[]) (char **) = {
	&hsh_cd,
	&hsh_help,
	&hsh_exit
};

int num_builtins(void)
{
	return (sizeof(builtin_str) / sizeof(char *));
}

int hsh_help(char **args)
{
	int i;

	printf("This is a replica of the Shell, a project for Holberton School\n");
	printf("Type program names and arguments, and hit enter.\n");
	printf("The following are built in:\n");

	for (i = 0; i < num_builtins(); i++)
	{
		printf("  %s\n", builtin_str[i]);
	}
	printf("Use the man command for information on other programs.\n");
	return (1);
}

int hsh_execute(char **args)
{
	int i;

	if (args[0] == NULL)
	{
		return (1);
	}

	for (i = 0; i < num_builtins(); i++)
	{
		if (strcmp(args[0], builtin_str[i]) == 0)
		{
			return ((*builtins[i])(args));
		}
	}
	return (launch_child(args));
}

int main(void)
{
	char *line = NULL, **args = NULL;
	int status;

	do
	{
		write(1, "$ ", 2);
		line = read_line();
		args = tokenize(line);
		status = hsh_execute(args);
		free(line);
		free(args);
	}
	while (status);
	return (0);
}
