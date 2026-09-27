#include <stdio.h>
#include <stdlib.h>
#include <string.h>    // strchr, strdup, strncpy に必要
#include <unistd.h>
#include <sys/wait.h>
#include <limits.h>    // PATH_MAX に必要
#include <sys/param.h>
#include "minishell.h"

void	fatal_error(const char *msg)
{
	dprintf(STDERR_FILENO, "Fatal Error: %s\n", msg);
	exit(1);
}
char	*search_path(const char *filename)
{
	char	path[PATH_MAX];
	char	*value;
	char	*end;

	// ① "./a.out" や "/bin/ls" と直打ちされた時の対応
	if (strchr(filename, '/'))
	{
		if (access(filename, X_OK) == 0)
			return (strdup(filename));
		return (NULL);
	}

	value = getenv("PATH");
	if (!value)
		return (NULL);

	while (*value)
	{
		// bzeroの代わりに標準のmemsetを使用
		memset(path, 0, PATH_MAX);
		end = strchr(value, ':');

		if (end)
		{
			// strncpy は標準関数なのでそのまま使用可能
			strncpy(path, value, end - value);
		}
		else
		{
			// ★自作の ft_strlcpy を使用
			ft_strlcpy(path, value, PATH_MAX);
		}

		// ★自作の ft_strlcat を使用
		ft_strlcat(path, "/", PATH_MAX);
		ft_strlcat(path, filename, PATH_MAX);

		if (access(path, X_OK) == 0)
		{
			char	*dup;

			dup = strdup(path);
			if (dup == NULL)
				fatal_error("strdup");
			return (dup);
		}
		if (end == NULL)
			return (NULL);
		value = end + 1;
	}
	return (NULL);
}


// --- 実行エンジン本体 ---
int    execution(char *line)
{
    extern char **environ;
    char        **command;
    char        *final_path;
    pid_t       pid;
    int         wstatus;
	int         exit_status = 0;

    // ★自作の ft_split でスペース区切りにする
    command = ft_split(line, ' ');
    if (command == NULL || command[0] == NULL)
        return (0); // 空入力なら何もしない

    pid = fork();
    if (pid < 0)
        fatal_error("fork");
    else if (pid == 0)
    {
        // 子プロセスでパスを検索
        final_path = search_path(command[0]);
        if (final_path == NULL)
        {
            dprintf(STDERR_FILENO, "minishell: %s: command not found\n", command[0]);
            exit(127);
        }

        // パスが見つかったら実行！
        execve(final_path, command, environ);
        fatal_error("execve");
    }
    else
    {
        // 親プロセスは待つ
        waitpid(pid, &wstatus, 0);
// ★追加：子供が正常に終了したら、そのステータスコードを抜き出す
        if (WIFEXITED(wstatus))
            exit_status = WEXITSTATUS(wstatus);
    }
	return (exit_status); // ★追加：親プロセスがこれを返す
}
