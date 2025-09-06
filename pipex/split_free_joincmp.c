/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gimaie <gimaie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 15:17:17 by gimaie            #+#    #+#             */
/*   Updated: 2025/09/01 09:57:03 by gimaie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*ss1;
	unsigned char	*ss2;

	ss1 = (unsigned char *)s1;
	ss2 = (unsigned char *)s2;
	while (*ss1 == *ss2 && *ss1 && n > 0)
	{
		ss1++;
		ss2++;
		n--;
	}
	if (n == 0)
		return (0);
	return (*ss1 - *ss2);
}

static size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
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

void	free_split(char **be_freed)
{
	int	i;

	if (be_freed == NULL)
		return ;
	i = 0;
	while (be_freed[i] != NULL)
	{
		free(be_freed[i]);
		i++;
	}
	free(be_freed);
}

void	free_split_2times(char **first_freed, char **second_freed)
{
	if (first_freed == NULL && second_freed == NULL)
		return ;
	free_split(first_freed);
	free_split(second_freed);
}
