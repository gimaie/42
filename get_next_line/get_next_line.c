/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gimaie <gimaie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 14:07:51 by gimaie            #+#    #+#             */
/*   Updated: 2025/08/16 15:29:03 by gimaie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*return_rem_clear(char **prem, char *buf)
{
	char	*line;

	free(buf);
	line = *prem;
	*prem = NULL;
	return (line);
}

// どこかでマロックして確保したメモリを書き換えるときは新しい入れ物を作って古い方はフリーしてアドレスを書き換える。

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

char	*fin_gnl(char **rem, char *buf)
{
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
	static char	*rem;
	char		*buf;
	char		*line;
	char		*nl;

	if (fd < 0)
		return (NULL);
	buf = malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	if (!rem)
	{
		rem = ft_strdup("");
		if (rem == NULL)
		{
			free(buf);
			return (NULL);
		}
	}
	nl = ft_strchr(rem, '\n');
	if (nl)
		return (check_rem(&rem, nl, buf));
	line = read_manage_rem(&rem, buf, fd);
	return (line);
}

// int	main(void)
// {
// 	int		fd;
// 	char	*line;

// 	fd = 2;
// 	while ((line = get_next_line(fd)) != NULL)
// 	{
// 		write(1, line, ft_strlen(line));
// 		free(line);
// 	}
// 	return (0);
// }

// int main(void)
// {
//     char    *line;
// 	int		fd;

// 	fd = open("text.txt", O_RDONLY);
// 	if (fd < 0)
// 		return (1);
//     while ((line = get_next_line(fd)) != NULL)
//     {
//         printf("%s", line);
//         free(line);
//     }
// 	close(fd);
//     return 0;
// }

// char	*get_next_line(int fd)
// {
// 	static char *rem;
// 	char		*buf;
// 	char		*line;
// 	size_t		i;
// 	size_t		j;
// 	int			flag;
// 	ssize_t		rn;
// 	char		*nl;
// 	char		*nl2;
// 	char		*tmp;
// 	char		*temp2;

// 	flag = 0;
// 	nl2 = ft_strchr(rem, '\n');
// 	if (nl2)
// 	{
// 		j = 0;
// 		while (rem[j] != nl2)
// 			j++;
// 		temp2 = strndup(rem, j);
// 		rem = nl2 + 1;
// 		return(temp2);
// 	}
// 	while(flag == 0)
// 	{
// 		buf = malloc(BUFFER_SIZE + 1);
// 		rn = read(fd, buf, BUFFER_SIZE);
// 		buf[rn] = '\0';
// 		i = 0;
// 		nl = ft_strchr(buf, '\n');
// 		if (nl)
// 		{
// 			while (buf[i] != *nl)
// 				i++;
// 			tmp = strndup(buf, i);
// 			line = strjoin(rem, tmp);
// 			rem = nl + 1;
// 			return (line);
// 		}
// 		else
// 			rem = ft_strdup(buf);
// 	}
// 	return (NULL);
// }
