/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gimaie <gimaie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 15:37:16 by gimaie            #+#    #+#             */
/*   Updated: 2025/05/14 11:15:14 by gimaie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdint.h>

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;
	size_t	total;

	if (size != 0 && nmemb > SIZE_MAX / size)
		return (NULL);
	total = nmemb * size;
	if (total == 0)
		total = 1;
	ptr = malloc(total);
	if (ptr == NULL)
		return (NULL);
	ft_bzero(ptr, nmemb * size);
	return (ptr);
}

// int	main(void)
// {
// 	int	*i;
// 	size_t	n;
// 	size_t	j;

// 	n = 5;
// 	i = ft_calloc(n, sizeof(int));
// 	if (i == NULL)
// 		return (1);
// 	j = 0;
// 	while (j < n)
// 	{
// 		printf("%d ", i[j]);
// 		j++;
// 	}
// 	free(i);
// 	return (0);
// }
