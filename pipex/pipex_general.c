/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_general.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gimaie <gimaie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 09:33:04 by gimaie            #+#    #+#             */
/*   Updated: 2025/09/01 13:39:28 by gimaie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child1_process(char **argv, char **env, int *pipefd)
{
	int		infile_fd;

		infile_fd = open(argv[1], O_RDONLY);
		if (infile_fd == -1)
			perror_exit(argv[1]);
		if (dup2(infile_fd, 0) == -1)
			perror_exit("dup2");
		if (close(infile_fd) == -1)
			perror_exit(argv[1]);
		if (dup2(pipefd[1], 1) == -1)
			perror_exit("dup2");
		if (close(pipefd[0]) == -1)
			perror_exit("close");
		if (close(pipefd[1]) == -1)
			perror_exit("close");
		exe_execve(argv, env, 2);
}

void	child2_process(char **argv, char **env, int *pipefd)
{
	int		outfile_fd;

		if (dup2(pipefd[0], 0) == -1)
			perror_exit("dup2");
		if (close(pipefd[0]) == -1)
			perror_exit("close");
		if (close(pipefd[1]) == -1)
			perror_exit("close");
		outfile_fd = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
		if (outfile_fd == -1)
			perror_exit(argv[4]);
		if (dup2(outfile_fd, 1) == -1)
			perror_exit("dup2");
		if (close(outfile_fd) == -1)
			perror_exit("close");
		exe_execve(argv, env, 3);
}

int	pipex(int argc, char **argv, char **env)
{
	int		pipefd[2];
	pid_t	pid1;
	pid_t	pid2;

	if (argc != 5)
		return (argc_not_five());
	if (pipe(pipefd) == -1)
		perror_exit("pipe");
	pid1 = fork();
	if (pid1 == -1)
		perror_exit("fork");
	if (pid1 == 0)
		child1_process(argv, env, pipefd);
	waitpid(pid1, NULL, 0);
	pid2 = fork();
	if (pid2 == -1)
		perror_exit("fork");
	if (pid2 == 0)
		child2_process(argv, env, pipefd);
	close(pipefd[0]);
	close(pipefd[1]);
	waitpid(pid2, NULL, 0);
	return (0);
}

int	main(int argc, char **argv, char **env)
{
	return (pipex(argc, argv, env));
}

// void	pipex(char **argv, char **env)
// {
// 	int		pipefd[2];
// 	pid_t	pid1;
// 	pid_t	pid2;
// 	int		infile_fd;
// 	int		outfile_fd;

// 	if (pipe(pipefd) != 0)
// 	{
// 		perror("pipe fail");
// 		exit(1);
// 	}
// 	pid1 = fork();
// 	if (pid1 == 0)
// 	{
// 		infile_fd = open(argv[1], O_RDONLY);
// 		dup2(infile_fd, 0);
// 		close(infile_fd);

// 		dup2(pipefd[1], 1);
// 		close(pipefd[0]);
// 		close(pipefd[1]);
// 		exe_execve(argv, env, 2);
// 	}

// 	pid2 = fork();
// 	if (pid2 == 0)
// 	{
// 		dup2(pipefd[0], 0);
// 		close(pipefd[0]);
// 		close(pipefd[1]);

// 		outfile_fd = open(argv[4], O_WRONLY);
// 		dup2(outfile_fd, 1);
// 		close(outfile_fd);
// 		exe_execve(argv, env, 3);
// 	}
// 	close(pipefd[0]);
// 	close(pipefd[1]);
// 	waitpid(pid1);
// 	waitpid(pid2);
// }

// int	main(int argc, char **argv, char **env)
// {
// 	pipex(argv, env);
// }













// char	*get_each_path()
