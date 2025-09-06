/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gimaie <gimaie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 15:01:11 by gimaie            #+#    #+#             */
/*   Updated: 2025/05/25 15:57:53 by gimaie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*check_rem(char **orem, char *nl, char *buf)
{
	char	*tmp;
	size_t	len;
	char	*nrem;

	free(buf);
	len = nl - *orem + 1;
	tmp = ft_strndup(*orem, len);
	nrem = ft_strdup(nl + 1);
	free(*orem);
	*orem = nrem;
	return (tmp);
}

char	*return_rem_clear(char **prem, char *buf)
{
	char	*line;

	free(buf);
	line = *prem;
	*prem = NULL;
	return (line);
}

char	*fin_gnl(char **rem, char *buf)
{
	if (buf)
		free(buf);
	if (*rem)
		free(*rem);
	*rem = NULL;
	return (NULL);
}

char	*read_manage_rem(char **rem, char *buf, int fd)
{
	char	*nl;
	char	*tmp;
	ssize_t	n;

	n = read(fd, buf, BUFFER_SIZE);
	while (n > 0)
	{
		buf[n] = '\0';
		tmp = ft_strjoin(*rem, buf);
		free(*rem);
		*rem = tmp;
		nl = ft_strchr(*rem, '\n');
		if (nl)
			return (check_rem(rem, nl, buf));
		n = read(fd, buf, BUFFER_SIZE);
	}
	if (n < 0)
		return (fin_gnl(rem, buf));
	if (n == 0 && (*rem)[0] != '\0')
		return (return_rem_clear(rem, buf));
	return (fin_gnl(rem, buf));
}

char	*get_next_line(int fd)
{
	static char	*rem[OPEN_MAX];
	char		*buf;
	char		*nl;
	char		*line;

	if (fd < 0 || fd >= OPEN_MAX)
		return (NULL);
	buf = malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	if (!rem[fd])
	{
		rem[fd] = ft_strdup("");
		if (rem[fd] == NULL)
		{
			free(buf);
			return (NULL);
		}
	}
	nl = ft_strchr(rem[fd], '\n');
	if (nl)
		return (check_rem(&rem[fd], nl, buf));
	line = read_manage_rem(&rem[fd], buf, fd);
	return (line);
}
