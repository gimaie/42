/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gimaie <gimaie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 18:56:01 by gimaie            #+#    #+#             */
/*   Updated: 2025/04/30 17:47:53 by gimaie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*us;

	us = (unsigned char *)s;
	while (n != 0)
	{
		if (*us == (unsigned char)c)
			return ((void *)us);
		us++;
		n--;
	}
	return (NULL);
}

// int main(void)
// {
// 	char *s = "abcde";
// 	char *p = ft_memchr(s, 'c', 5);

// 	printf("%c", *p);
// }
