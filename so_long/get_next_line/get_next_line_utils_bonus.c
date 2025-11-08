/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gimaie <gimaie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 16:01:20 by gimaie            #+#    #+#             */
/*   Updated: 2025/05/22 16:01:27 by gimaie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	while (*s != '\0')
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if ((char)c == '\0')
		return ((char *)s);
	return (NULL);
}

char	*ft_strdup(const char *s)
{
	size_t	len;
	char	*t;
	size_t	i;

	len = ft_strlen(s);
	t = malloc(len + 1);
	if (t == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		t[i] = s[i];
		i++;
	}
	t[i] = '\0';
	return (t);
}

char	*ft_strndup(const char *s, size_t n)
{
	size_t	i;
	char	*t;

	t = malloc(n + 1);
	if (t == NULL)
		return (NULL);
	i = 0;
	while (i < n && s[i])
	{
		t[i] = s[i];
		i++;
	}
	t[i] = '\0';
	return (t);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len;
	char	*s;
	char	*head;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	s = malloc(len + 1);
	if (s == NULL)
		return (NULL);
	head = s;
	while (*s1)
	{
		*s = *s1;
		s++;
		s1++;
	}
	while (*s2)
	{
		*s = *s2;
		s++;
		s2++;
	}
	*s = '\0';
	return (head);
}
