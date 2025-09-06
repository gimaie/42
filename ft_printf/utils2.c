/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gimaie <gimaie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 14:54:38 by gimaie            #+#    #+#             */
/*   Updated: 2025/05/18 12:22:49 by gimaie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_itoa_bhex(unsigned int u)
{
	char		*s;
	size_t		len;
	const char	*base;

	len = count_16(u);
	s = malloc(len + 1);
	if (s == NULL)
		return (0);
	base = "0123456789ABCDEF";
	s[len] = '\0';
	while (len > 0)
	{
		len--;
		s[len] = base[u % 16];
		u = u / 16;
	}
	return (s);
}

char	*ft_itoa_ptr(unsigned long l)
{
	char		*s;
	size_t		len;
	const char	*base;

	len = count_16_forptr(l);
	s = malloc(len + 1);
	if (s == NULL)
		return (0);
	base = "0123456789abcdef";
	s[len] = '\0';
	while (len > 0)
	{
		len--;
		s[len] = base[l % 16];
		l = l / 16;
	}
	return (s);
}

size_t	count_16_forptr(unsigned long l)
{
	size_t	i;

	i = 1;
	while (l >= 16)
	{
		l = l / 16;
		i++;
	}
	return (i);
}
