/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gimaie <gimaie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 16:25:41 by gimaie            #+#    #+#             */
/*   Updated: 2025/08/04 20:27:39 by gimaie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	simple_sort(int *arr, int size, int *ns)
{
	int	i;
	int	j;
	int	tmp;

	i = -1;
	while (++i < size)
		arr[i] = ns[i];
	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size - 1)
		{
			if (arr[j] > arr[j + 1])
			{
				tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
			j++;
		}
		i++;
	}
}

int	index_numbers(int *ns, int size)
{
	int	*tmp;
	int	i;
	int	j;

	tmp = malloc(sizeof(int) * size);
	if (tmp == NULL)
		return (0);
	simple_sort(tmp, size, ns);
	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			if (ns[i] == tmp[j])
			{
				ns[i] = j;
				break ;
			}
			j++;
		}
		i++;
	}
	free(tmp);
	return (1);
}
