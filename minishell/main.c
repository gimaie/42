#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <readline/readline.h>
#include <readline/history.h>
#include "minishell.h"

t_cmd	*tokenize(char *line)
{
	t_cmd	*cmd;
	//パイプを見つけるたびに対象のノードを切り替える
}

int	operation(char *line)
{
	t_cmd	*cmd;
	// cmd = tokenize(line);
	return (execution(line));
	// free_cmd(cmd);
}

int main(void)
{
	char *line = NULL;
	int status = 0;

	rl_outstream = stderr;
	while (1)
	{
		line = readline("minishell$ ");
		if (line == NULL)
			break;
		if (*line)
			add_history(line);
		status = operation(line);
		free(line);
	}
	return (status);
}
