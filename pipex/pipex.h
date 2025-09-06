/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gimaie <gimaie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 13:44:34 by gimaie            #+#    #+#             */
/*   Updated: 2025/09/06 19:26:18 by gimaie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef	PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <fcntl.h>

int		pipex(int argc, char **argv, char **env);
void	child1_process(char **argv, char **env, int *pipefd);
void	child2_process(char **argv, char **env, int *pipefd);
char	*find_path(char **env);
char	**store_path_into_array(char **env);
char	*ft_strjoin_2times(char *sepaprated_one_path, char *command0);
char	*search_command_in_path(char **command, char **separated_path);
char	*find_command_path(char **command, 	char **separated_path);
void	exe_execve(char **argv, char **env, int comm_num);
void	free_split(char **be_freed);
void	free_split_2times(char **first_freed, char **second_freed);
void	perror_exit(char *error_point);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	**ft_split(char const *s, char c);
char	**ft_split_space_tab(char const *s, char c1, char c2);
char	*ft_strjoin(char const *s1, char const *s2);
void	ft_putstr_fd(char *s, int fd);
int		argc_not_five();
void	command_not_found(char *command0);
void	fail_exe_free_finalpath(char *final_path);
char	*ft_strrchr(const char *s, int c);
char	*ft_strdup(const char *s);

#endif
