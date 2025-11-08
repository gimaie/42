/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gimaie <gimaie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 13:15:21 by gimaie            #+#    #+#             */
/*   Updated: 2025/05/17 17:32:15 by gimaie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	count_digits(unsigned int n)
{
	size_t	i;

	i = 1;
	while (n >= 10)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char			*s;
	size_t			len;
	int				sign;
	unsigned int	u;

	sign = (n < 0);
	if (n < 0)
		u = (unsigned int)-n;
	else
		u = (unsigned int)n;
	len = count_digits(u) + sign;
	s = malloc(len + 1);
	if (s == NULL)
		return (0);
	s[len] = '\0';
	while (len > 0)
	{
		s[len - 1] = u % 10 + '0';
		u = u / 10;
		len--;
	}
	if (sign == 1)
		s[0] = '-';
	return (s);
}

char	*ft_uitoa(unsigned int u)
{
	char			*s;
	size_t			len;

	len = count_digits(u);
	s = malloc(len + 1);
	if (s == NULL)
		return (0);
	s[len] = '\0';
	while (len > 0)
	{
		s[len - 1] = u % 10 + '0';
		u = u / 10;
		len--;
	}
	return (s);
}

size_t	count_16(unsigned int n)
{
	size_t	i;

	i = 1;
	while (n >= 16)
	{
		n = n / 16;
		i++;
	}
	return (i);
}

char	*ft_itoa_hex(unsigned int u)
{
	char		*s;
	size_t		len;
	const char	*base;

	len = count_16(u);
	s = malloc(len + 1);
	if (s == NULL)
		return (0);
	base = "0123456789abcdef";
	s[len] = '\0';
	while (len > 0)
	{
		len--;
		s[len] = base[u % 16];
		u = u / 16;
	}
	return (s);
}
