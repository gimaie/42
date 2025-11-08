/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gimaie <gimaie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 14:54:07 by gimaie            #+#    #+#             */
/*   Updated: 2025/05/25 14:00:42 by gimaie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

# ifndef OPEN_MAX
#  define OPEN_MAX 1024
# endif

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <limits.h>

char	*get_next_line(int fd);
char	*return_rem_clear(char **prem, char *buf);
char	*check_rem(char **orem, char *nl, char *buf);
char	*read_manage_rem(char **rem, char *buf, int fd);
char	*fin_gnl(char **rem, char *buf);

char	*ft_strchr(const char *s, int c);
size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s);
char	*ft_strndup(const char *s, size_t n);
char	*ft_strjoin(char const *s1, char const *s2);

#endif /*GET_NEXT_LINE_BONUS_H*/
