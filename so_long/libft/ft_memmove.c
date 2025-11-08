/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gimaie <gimaie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 19:10:48 by gimaie            #+#    #+#             */
/*   Updated: 2025/05/12 20:16:50 by gimaie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*a;
	unsigned char	*b;

	if ((dest == NULL && src == NULL) || n == 0)
		return (dest);
	a = (unsigned char *)src;
	b = (unsigned char *)dest;
	if (a < b && b < a + n)
	{
		while (n > 0)
		{
			n--;
			b[n] = a[n];
		}
	}
	else
	{
		dest = ft_memcpy(dest, src, n);
	}
	return (dest);
}
