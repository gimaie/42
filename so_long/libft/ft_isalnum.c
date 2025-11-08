/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gimaie <gimaie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 17:04:00 by gimaie            #+#    #+#             */
/*   Updated: 2025/05/12 16:08:57 by gimaie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
		return (1);
	else if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

// int main(void)
// {
// 	int a = 'X';
// 	int b = 'x';
// 	int c = 8;
// 	int d = '@';

// 	printf("%d%d%d%d", ft_isalnum(a), ft_isalnum(b),
//ft_isalnum(c), ft_isalnum(d));
// }
