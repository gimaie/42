/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gimaie <gimaie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 13:04:11 by gimaie            #+#    #+#             */
/*   Updated: 2025/05/08 10:18:13 by gimaie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int			sign;
	int			result;
	int			digit;
	const char	*p;

	sign = 1;
	result = 0;
	p = nptr;
	while (((*p >= '\t') && (*p <= '\r' )) || (*p == 32))
		p++;
	if (*p == '-' || *p == '+')
	{
		if (*p == '-')
			sign = sign * (-1);
		p++;
	}
	while (*p >= '0' && *p <= '9')
	{
		digit = *p - '0';
		result = result * 10 + digit;
		p++;
	}
	return (result * sign);
}

// int main(void)
// {
// 	const char nptr[] = "  -12423";
// 	printf("%d", ft_atoi(nptr));
// }
