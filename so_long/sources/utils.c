/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 10:46:45 by marvin            #+#    #+#             */
/*   Updated: 2025/10/08 10:46:45 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	unsigned char	*ss1;
	unsigned char	*ss2;

	ss1 = (unsigned char *)s1;
	ss2 = (unsigned char *)s2;
	while (*ss1 == *ss2 && *ss1)
	{
		ss1++;
		ss2++;
	}
	return (*ss1 - *ss2);
}

char	**free_array_and_return(char **array)
{
	int	i;

	i = 0;
	while (array[i] != NULL)
	{
		free(array[i]);
		i++;
	}
	free(array);
	return (NULL);
}
