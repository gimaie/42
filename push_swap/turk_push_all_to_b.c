/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_push_all_to_b.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gimaie <gimaie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 14:52:33 by gimaie            #+#    #+#             */
/*   Updated: 2025/08/06 17:31:49 by gimaie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	execute_moves(t_stack *a, t_stack *b, t_move_cost smallest_cost)
{
	while (smallest_cost.ra_moves > 0 && smallest_cost.rb_moves > 0)
	{
		rr(a, b);
		smallest_cost.ra_moves--;
		smallest_cost.rb_moves--;
	}
	while (smallest_cost.rra_moves > 0 && smallest_cost.rrb_moves > 0)
	{
		rrr(a, b);
		smallest_cost.rra_moves--;
		smallest_cost.rrb_moves--;
	}
	execute_moves_each(a, b, smallest_cost);
	pb(a, b);
}

void	execute_moves_each(t_stack *a, t_stack *b, t_move_cost smallest_cost)
{
	while (smallest_cost.ra_moves > 0)
	{
		ra(a);
		smallest_cost.ra_moves--;
	}
	while (smallest_cost.rb_moves > 0)
	{
		rb(b);
		smallest_cost.rb_moves--;
	}
	while (smallest_cost.rra_moves > 0)
	{
		rra(a);
		smallest_cost.rra_moves--;
	}
	while (smallest_cost.rrb_moves > 0)
	{
		rrb(b);
		smallest_cost.rrb_moves--;
	}
}

void	push_all_to_b(t_stack *a, t_stack *b)
{
	t_list		*current_a_node;
	t_move_cost	smallest_cost;
	t_move_cost	cost_for_this_node;
	int			initial_check;

	if (a->size >= 1)
		pb(a, b);
	if (a->size >= 1)
		pb(a, b);
	while (a->size >= 3)
	{
		smallest_cost.total_cost = INT_MAX;
		current_a_node = a->head;
		initial_check = 0;
		while (current_a_node != a->head || initial_check == 0)
		{
			initial_check = 1;
			cost_for_this_node = calculate_cost_a_to_b(a, b, current_a_node);
			if (cost_for_this_node.total_cost < smallest_cost.total_cost)
				smallest_cost = cost_for_this_node;
			current_a_node = current_a_node->next;
		}
		execute_moves(a, b, smallest_cost);
	}
}
