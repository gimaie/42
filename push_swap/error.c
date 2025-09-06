/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gimaie <gimaie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 15:19:48 by gimaie            #+#    #+#             */
/*   Updated: 2025/08/07 20:01:02 by gimaie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	*clean_command(int argc, char **argv, int *out_count)
{
	long	*ns;
	int		i;
	int		j;

	if (argc < 2 || argv == NULL)
		return (NULL);
	ns = malloc(sizeof(long) * (argc - 1));
	if (ns == NULL)
		return (NULL);
	i = 0;
	j = 1;
	while (j < argc)
	{
		ns[i] = ft_atol(argv[j]);
		i++;
		j++;
	}
	*out_count = i;
	return (ns);
}

int	int_range(long *ns, int *count)
{
	int	i;

	if (ns == NULL || count == NULL)
		return (0);
	i = 0;
	while (i < *count)
	{
		if (ns[i] < INT_MIN || ns[i] > INT_MAX)
		{
			write(2, "Error\n", 7);
			return (0);
		}
		i++;
	}
	return (1);
}

int	sorted(long *ns, int *count)
{
	int	i;
	int	j;

	if (ns == NULL || count == NULL)
		return (0);
	i = 0;
	j = 1;
	while (j < *count)
	{
		if (ns[i] > ns[j])
			return (1);
		i++;
		j++;
	}
	return (0);
}

int	duplicated(long *ns, int *count)
{
	int	i;
	int	j;

	if (ns == NULL || count == NULL)
		return (0);
	i = 0;
	while (i + 1 < *count)
	{
		j = i + 1;
		while (j < *count)
		{
			if (ns[i] == ns[j])
			{
				write(2, "Error\n", 7);
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	numeric(int argc, char **argv)
{
	int	i;
	int	j;

	j = 1;
	while (j < argc)
	{
		i = 0;
		if (argv[j][0] == '+' || argv[j][0] == '-')
			i++;
		if (argv[j][i] == '\0')
			return (0);
		while (argv[j][i])
		{
			if (argv[j][i] < '0' || argv[j][i] > '9')
			{
				write(2, "Error\n", 7);
				return (0);
			}
			i++;
		}
		j++;
	}
	return (1);
}
