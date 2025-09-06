/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execve.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gimaie <gimaie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 14:31:36 by gimaie            #+#    #+#             */
/*   Updated: 2025/09/06 19:46:18 by gimaie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*find_path(char **env)
{
	int	i;

	i = 0;
	while (env[i] != NULL)
	{
		if (ft_strncmp(env[i], "PATH=", 5) == 0)
			return (env[i] + 5);
		i++;
	}
	return(NULL);
}

char	**store_path_into_array(char **env)
{
	char	*path;
	char	**separated_path;

	path = find_path(env);
	if (path == NULL)
        return (NULL);
	separated_path = ft_split(path, ':');
	if (separated_path == NULL)
		return (NULL);
	return (separated_path);
}

char	*search_command_in_path(char **command, char **separated_path)
{
	char	*final_path;
	int		i;

	i = 0;
	while (separated_path[i] != NULL)
	{
		final_path = ft_strjoin_2times(separated_path[i], command[0]);
		if (final_path == NULL)
		{
			free_split_2times(separated_path, command);
			perror_exit("malloc");
		}
		if (access(final_path, X_OK) == 0)
		{
			free_split(separated_path);
			return (final_path);
		}
		free(final_path);
		i++;
	}
	free_split(separated_path);
	return(NULL);
}
char	*find_command_path(char **command, char **env)
{
	char	**separated_path;

	if (ft_strrchr(command[0], '/'))
	{
		if (access(command[0], X_OK) != 0)
			return (NULL);
		return (ft_strdup(command[0]));
	}
	else
	{
		separated_path = store_path_into_array(env);
		if (separated_path == NULL)
		{
			free_split(command);
			perror_exit("malloc");
		}
		return (search_command_in_path(command, separated_path));
	}
}

void    exe_execve(char **argv, char **env, int comm_num)
{
    char    **command;
    char    *final_path;
    char    *tmp;

    if (argv == NULL || env == NULL || comm_num < 1)
        perror_exit("Invalid parameters");
    command = ft_split(argv[comm_num], ' ');
    if (command == NULL || command[0] == NULL)
        perror_exit("malloc");
    final_path = find_command_path(command, env);
    if (final_path == NULL)
    {
		command_not_found(command[0]);
        free_split(command);
		exit(127);
    }
    tmp = ft_strrchr(command[0], '/');
    if (tmp != NULL)
        command[0] = tmp + 1;

    execve(final_path, command, env);
    free(final_path);
    free_split(command);
    perror_exit("execve");
}

// char	*find_command_path(char **argv, char **env, int comm_num)
// {
// 	char	**separated_path;
// 	char	**command;
// 	int		i;
// 	char	*tmp;
// 	char	*final_path;
// 	int		can_access;

// 	separated_path = store_path_into_array(env);
// 	if (separated_path == NULL)
// 	{
// 		// error処理
// 		return (NULL);
// 	}
// 	command = ft_split(argv[comm_num], ' ');
// 	if (command == NULL)
// 	{
// 		// error処理
// 		return (NULL);
// 	}
// 	i = 0;
// 	while (separated_path[i] != NULL)
// 	{
// 		tmp = ft_strjoin(separated_path[i], "/");
// 		final_path = ft_strjoin(tmp, command[0]);
// 		if (tmp == NULL || final_path == NULL)
// 		{
// 			// error処理
// 			return (NULL);
// 		}
// 		free(tmp);
// 		can_access = access(final_path, X_OK);
// 		if (can_access == 0)
// 		{
// 			free_split(separated_path);
// 			// commandは後で使うからfreeしない
// 			// でもcommandは引き継げないから結局この関数は分けるべき
// 			return (final_path);
// 		}
// 		free(final_path);
// 		i++;
// 	}
// 	free_split(separated_path);
// 	free_split(command);
// 	return (NULL);
// 	// この関数でフリーすべきだと思う
// }


// char	*get_command_(char **argv, int comm_num)
// {
// 	char	**comm;

// 	if (argv == NULL || comm_num < 1)
// 		return (NULL);
// 	comm = ft_split(argv[comm_num], ' ');
// 	if (comm == NULL)
// 		return (NULL);

// }


// char	*find_command_path(char *command0, 	char **separated_path)
// {
// 	int		i;
// 	char	*final_path;
// 	int		can_access;

// 	if (command0 == NULL || separated_path == NULL)
// 		return (NULL);
// 	i = 0;
// 	while (separated_path[i] != NULL)
// 	{
// 		final_path = ft_strjoin_2times(separated_path[i], command0);
// 		if (final_path == NULL)
// 			return (NULL);
// 		can_access = access(final_path, X_OK);
// 		if (can_access == 0)
// 		{
// 			free_split(separated_path);
// 			return (final_path);
// 		}
// 		free(final_path);
// 		i++;
// 	}
// 	return (NULL);
// }

// void	exe_execve(char **argv, char **env, int comm_num)
// {
// 	char	**command;
// 	char	**separated_path;
// 	char	*final_path;

// 	if (argv == NULL || env == NULL || comm_num < 1)
// 	{
// 		ft_putstr_fd("bash: Parameter Invalid\n", 2);
// 		exit(1);
// 	}
// 	command = ft_split_space_tab(argv[comm_num], ' ', '	');
// 	separated_path = store_path_into_array(env);
// 	if (command == NULL || separated_path == NULL)
// 	{
// 		free_split_2times(command, separated_path);
// 		perror_exit("bash: malloc");
// 	}
// 	final_path = find_command_path(command[0], separated_path);
// 	if (final_path == NULL)
// 	{
// 		free_split_2times(command, separated_path);
// 		command_not_found(command[0]);
// 	}
// 	execve(final_path, command, env);
// 	free_split_2times(command, separated_path);
// 	fail_exe_free_finalpath(final_path);
// }

// void	exe_execve(char **argv, char **env, int comm_num)
// {
// 	char	**command;
// 	char	**separated_path;
// 	char	*final_path;
// 	char	*tmp;

// 	if (argv == NULL || env == NULL || comm_num < 1)
// 		error_exit("Invalid parameters");
// 	command = ft_split_space_tab(argv[comm_num], ' ', '	');
// 	if (command == NULL || command[0] == NULL)
// 		perror_exit("bash: malloc");

// 	if (ft_strrchr(argv[comm_num], '/'))
// 	{
// 		if (access(command[0], X_OK) != 0)
// 		{
// 			free_split(command);
// 			perror_exit(command[0]);
// 		}
// 		final_path = ft_strdup(command[0]);
// 		if (final_path == NULL)
// 		{
// 			free_split(command);
// 			perror_exit("malloc");
// 		}
// 	}

// 	else
// 	{
// 		separated_path = store_path_into_array(env);
// 		if (separated_path == NULL)
// 		{
// 			free_split(command);
// 			perror_exit("bash: malloc");
// 		}
// 		final_path = find_command_path(command[0], separated_path);
// 		if (final_path == NULL)
// 		{
// 			free_split_2times(command, separated_path);
// 			command_not_found(command[0]);
// 		}
// 	}

// 	tmp = ft_strrchr(command[0], '/');
// 	if (tmp != NULL)
// 		command[0] = tmp + 1;
// 	execve(final_path, command, env);
// 	free(final_path);
// 	free_split(command);
// 	perror_exit("execve");
// }
