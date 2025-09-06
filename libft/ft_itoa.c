/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gimaie <gimaie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 10:37:40 by gimaie            #+#    #+#             */
/*   Updated: 2025/05/12 17:20:13 by gimaie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_digits(unsigned int n)
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
// int	main(void)
// {
// 	int n = -9;

// 	printf("%s", ft_itoa(n));
// }
