/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_turk_ver.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gimaie <gimaie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 12:52:02 by gimaie            #+#    #+#             */
/*   Updated: 2025/08/04 20:28:48 by gimaie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	align_final_stack(t_stack *a)
{
	t_list	*min_node;
	int		min_node_index;

	min_node = get_min_node(a);
	if (min_node == NULL)
		return ;
	min_node_index = get_node_index(a, min_node);
	if (min_node_index <= a->size / 2)
	{
		while (min_node_index > 0)
		{
			ra(a);
			min_node_index--;
		}
	}
	else
	{
		min_node_index = a->size - min_node_index;
		while (min_node_index > 0)
		{
			rra(a);
			min_node_index--;
		}
	}
}

void	sort_turk(t_stack *a, t_stack *b)
{
	push_all_to_b(a, b);
	push_all_to_a(a, b);
	align_final_stack(a);
}
