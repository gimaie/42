/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gimaie <gimaie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 16:56:56 by gimaie            #+#    #+#             */
/*   Updated: 2025/04/30 17:45:01 by gimaie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, '\0', n);
}

// int	main(void)
// {
// 	unsigned char array[10] = {'a','b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j'};

// 	ft_bzero(array, 5);
// 	for (int i = 0; i < 10; i++)
// 	{
//         printf("array[%d] = %d\n", i, array[i]);
// 	}
// }
