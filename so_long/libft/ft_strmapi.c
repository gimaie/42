/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gimaie <gimaie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 14:53:29 by gimaie            #+#    #+#             */
/*   Updated: 2025/05/08 15:49:00 by gimaie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*www;
	size_t			len;
	unsigned int	i;

	if (s == NULL || f == NULL)
		return (NULL);
	len = ft_strlen(s);
	www = malloc(len + 1);
	if (www == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		www[i] = f(i, s[i]);
		i++;
	}
	www[i] = '\0';
	return (www);
}

// static char	c_toupper(unsigned int i, char c)
// {
// 	if (c >= 'a' && c <= 'z')
// 	{
// 		c = c - 32;
// 	}
// 	return (c);
// }

// int	main (void)
// {
// 	char const *a = "abcdefg";
// 	unsigned int i = 0;
// 	char *res= ft_strmapi(a, c_toupper);
// 	printf("%s", res);
// }
