/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gimaie <gimaie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 15:25:30 by gimaie            #+#    #+#             */
/*   Updated: 2025/09/06 19:22:27 by gimaie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_strrchr(const char *s, int c)
{
	const char	*last;

	last = NULL;
	while (*s)
	{
		if (*s == (char)c)
			last = s;
		s++;
	}
	if ((char)c == '\0')
		return ((char *)s);
	return ((char *)last);
}

static size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

static size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size != 0)
	{
		while (i < size - 1 && src[i])
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (ft_strlen(src));
}

char	*ft_strdup(const char *s)
{
	size_t	len;
	char	*t;

	len = ft_strlen(s);
	t = malloc(len + 1);
	if (t == NULL)
		return (NULL);
	ft_strlcpy(t, s, (len + 1));
	return (t);
}

char	*ft_strjoin_2times(char *sepaprated_one_path, char *command0)
{
	char	*tmp;
	char	*final_path;

	if (sepaprated_one_path == NULL || command0 == NULL)
		return (NULL);
	tmp = ft_strjoin(sepaprated_one_path, "/");
	if (tmp == NULL)
		return (NULL);
	final_path = ft_strjoin(tmp, command0);
	if (final_path == NULL)
	{
		free(tmp);
		return (NULL);
	}
	free(tmp);
	return (final_path);
}
