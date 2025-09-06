/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_push_all_to_a.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gimaie <gimaie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 16:18:30 by gimaie            #+#    #+#             */
/*   Updated: 2025/08/04 20:57:59 by gimaie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_optimal_insert_pos_in_a(t_stack *a, int value_from_b)
{
	int		initial_check_done;
	t_list	*current;
	t_list	*max_node;
	t_list	*min_node;

	if (a == NULL || a->head == NULL || a->size == 0)
		return (0);
	max_node = get_max_node(a);
	min_node = get_min_node(a);
	if (value_from_b > max_node->content || value_from_b < min_node->content)
		return (get_node_index(a, min_node));
	current = a->head;
	initial_check_done = 0;
	while (current != a->head || initial_check_done == 0)
	{
		initial_check_done = 1;
		if (value_from_b > current->content
			&& value_from_b < current->next->content)
			return (get_node_index(a, current->next));
		current = current->next;
	}
	return (-1);
}

void	push_all_to_a(t_stack *a, t_stack *b)
{
	int		how_many_rotate;

	while (b->size > 0)
	{
		how_many_rotate = find_optimal_insert_pos_in_a(a, b->head->content);
		if (how_many_rotate <= a->size / 2)
		{
			while (how_many_rotate > 0)
			{
				ra(a);
				how_many_rotate--;
			}
		}
		else
		{
			how_many_rotate = a->size - how_many_rotate;
			while (how_many_rotate > 0)
			{
				rra(a);
				how_many_rotate--;
			}
		}
		pa(b, a);
	}
}
