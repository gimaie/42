/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gimaie <gimaie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 16:50:56 by gimaie            #+#    #+#             */
/*   Updated: 2025/05/12 17:25:46 by gimaie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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

// int	main(void)
// {
// 	const char	*a;
// 	const char	*b;
// 	a= "test\200";
// 	b = "test\0";
// 	printf("%d", ft_strncmp(a, b, 7));
// }
