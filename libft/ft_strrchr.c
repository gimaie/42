/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gimaie <gimaie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 14:37:36 by gimaie            #+#    #+#             */
/*   Updated: 2025/05/12 17:18:55 by gimaie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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

// char *ft_strchr(const char *s, int c)
// {
// 	size_t i;

// 	i = 0;
// 	while (*s != '\0')
// 	{
// 		if (*s == c)
// 			return ((char *)s);
// 		s++;
// 	}
// 	if (c == '\0')
// 		return ((char *)s);
// 	return (NULL);
// }

// int	main(void)
// {
// 	const char	*s = "teste";
// 	// printf("%p\n", ft_strchr(s, c));
// 	printf("%p", ft_strrchr(s, '\0' + 1024));
// }

// char	*ft_strrchr(const char *s, int c)
// {
// 	int	i;
// 	int	t;

// 	i = 0;
// 	while (*s)
// 	{
// 		s++;
// 		i++;
// 	}
// 	t = s - i;
// 	if (c == '\0')
// 		return ((char *)s);
// 	while (i >= 0)
// 	{
// 		if (*s == c)
// 			return ((char *)s);
// 		i--;
// 		s--;
// 	}
// 	return (NULL);
// }
