/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   general_push_swap.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gimaie <gimaie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 19:03:05 by gimaie            #+#    #+#             */
/*   Updated: 2025/08/06 19:46:37 by gimaie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(int argc, char **argv)
{
	int		*ns;
	int		size;
	t_stack	*a;
	t_stack	*b;

	size = argc - 1;
	ns = validate_args(argc, argv);
	if (ns == NULL)
		return ;
	a = make_stack_a(ns, size);
	b = make_stack_b(a);
	if (a == NULL || b == NULL)
		return ;
	sort_stack(a, b);
	free_stack(a);
	free_stack(b);
}

int	main(int argc, char **argv)
{
	push_swap(argc, argv);
	return (0);
}
