/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   when_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gimaie <gimaie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 09:59:19 by gimaie            #+#    #+#             */
/*   Updated: 2025/09/06 19:47:30 by gimaie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_putstr_fd(char *s, int fd)
{
	if (s == NULL)
		return ;
	while (*s)
	{
		write(fd, s, 1);
		s++;
	}
}

int	argc_not_five()
{
	ft_putstr_fd("Error: Invalid number of arguments\n", 2);
	return (1);
}

void	perror_exit(char *error_point)
{
	ft_putstr_fd("bash: ", 2);
	perror(error_point);
	exit(1);
}

void	command_not_found(char *command0)
{
	ft_putstr_fd(command0, 2);
	ft_putstr_fd(": command not found\n", 2);
}

void	fail_exe_free_finalpath(char *final_path)
{
	ft_putstr_fd("bash: ", 2);
	perror(final_path);
	free(final_path);
	exit(126);
}
