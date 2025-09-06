/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gimaie <gimaie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 18:07:22 by gimaie            #+#    #+#             */
/*   Updated: 2025/08/07 19:57:09 by gimaie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_valid_long_array(long *long_ns, int *count)
{
	if (!int_range(long_ns, count))
		return (0);
	if (!duplicated(long_ns, count))
		return (0);
	if (!sorted(long_ns, count))
		return (0);
	return (1);
}

int	*create_ints(long *long_ns, int size)
{
	int	*int_ns;
	int	i;

	int_ns = malloc(sizeof(int) * size);
	if (int_ns == NULL)
		return (NULL);
	i = 0;
	while (i < size)
	{
		int_ns[i] = (int)long_ns[i];
		i++;
	}
	return (int_ns);
}

int	*validate_args(int argc, char **argv)
{
	long	*long_ns;
	int		*final_ns;
	int		count;

	if (argc < 2 || !numeric(argc, argv))
		return (NULL);
	long_ns = clean_command(argc, argv, &count);
	if (long_ns == NULL)
		return (NULL);
	if (!is_valid_long_array(long_ns, &count))
	{
		free(long_ns);
		return (NULL);
	}
	final_ns = create_ints(long_ns, count);
	free(long_ns);
	if (final_ns == NULL)
		return (NULL);
	if (!(index_numbers(final_ns, count)))
	{
		free(final_ns);
		return (NULL);
	}
	return (final_ns);
}

// int	*validate_args(int argc, char **argv)
// {
// 	long	*ns;
// 	int		count;
// 	int		flag;

// 	flag = 1;
// 	ns = NULL;
// 	if (!(numeric(argc, argv)) || argc < 2)
// 		return (NULL);
// 	ns = clean_command(argc, argv, &count);
// 	if (ns == NULL)
// 		flag = 0;
// 	else if (!(int_range(ns, &count)))
// 		flag = 0;
// 	else if (!(sorted(ns, &count)))
// 		flag = 0;
// 	else if (!(duplicated(ns, &count)))
// 		flag = 0;
// 	if (!flag)
// 	{
// 		free(ns);
// 		return (NULL);
// 	}
// 	return (ns);
// }
