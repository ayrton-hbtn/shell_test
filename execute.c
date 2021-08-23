#include "shell.h"
/*
char *builtin_str[] = {
  "cd",
  "help",
  "exit"
};

int (*builtins[])(char **) = {
  &hsh_cd,
  &hsh_help,
  &hsh_exit
};

int num_builtins() {
  return sizeof(builtin_str) / sizeof(char *);
}

int hsh_execute(char **args)
{
  int i;

  if (args[0] == NULL) {
    // An empty command was entered.
    return (1);
  }

  for (i = 0; i < num_builtins(); i++) {
    if (strcmp(args[0], builtin_str[i]) == 0) {
      return (*builtins[i])(args);
    }
  }

  return launch_child(args);
}
*/
