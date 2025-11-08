/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gimaie <gimaie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 17:09:04 by gimaie            #+#    #+#             */
/*   Updated: 2025/05/12 20:11:36 by gimaie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*a;
	unsigned char	*b;
	int				i;

	if ((dest == NULL && src == NULL) || n == 0)
		return (dest);
	a = (unsigned char *)src;
	b = (unsigned char *)dest;
	i = 0;
	while (n > 0)
	{
		b[i] = a[i];
		i++;
		n--;
	}
	return (dest);
}

// int	main(void)
// {
// 	unsigned char	src[] = "abcdefg";
// 	unsigned char	dest[] = "0000000";
// 	ft_memcpy(dest, src, 5);
// 	printf("%s\n%s", src, dest);
// }
