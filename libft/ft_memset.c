/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gimaie <gimaie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 12:24:54 by gimaie            #+#    #+#             */
/*   Updated: 2025/04/30 17:46:07 by gimaie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	int				i;
	unsigned char	*t;

	i = 0;
	t = (unsigned char *) s;
	while (n > 0)
	{
		t[i] = c;
		i++;
		n--;
	}
	return (s);
}

// int	main(void)
// {
// 	unsigned char array[10] = {'a','b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j'};

// 	ft_memset(array, 5, 5);
// 	for (int i = 0; i < 10; i++)
// 	{
//         printf("array[%d] = %d\n", i, array[i]);
// 	}
// }
