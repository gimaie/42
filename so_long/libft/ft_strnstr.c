/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gimaie <gimaie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 21:02:00 by gimaie            #+#    #+#             */
/*   Updated: 2025/04/30 17:49:15 by gimaie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	const char	*b;
	const char	*l;
	size_t		i;

	if (*little == '\0')
		return ((char *)big);
	while (*big && len > 0)
	{
		l = little;
		b = big;
		i = len;
		while (*l && *b && i > 0 && *l == *b)
		{
			l++;
			b++;
			i--;
		}
		if (*l == '\0')
			return ((char *)big);
		big++;
		len--;
	}
	return (NULL);
}
