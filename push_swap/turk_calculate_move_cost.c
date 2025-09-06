/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_calculate_move_cost.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gimaie <gimaie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 15:27:21 by gimaie            #+#    #+#             */
/*   Updated: 2025/08/06 17:56:44 by gimaie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_move_cost	init_move_cost(void)
{
	t_move_cost	cost;

	cost.ra_moves = 0;
	cost.rb_moves = 0;
	cost.rra_moves = 0;
	cost.rrb_moves = 0;
	cost.total_cost = 0;
	return (cost);
}

int	calc_rot_moves(int stack_size, int index, int type)
{
	if (index == 0)
		return (0);
	if (type == 0)
		return (index);
	return (stack_size - index);
}

void	*ft_memset(void *s, int c, size_t n)
{
	int				i;
	unsigned char	*t;

	i = 0;
	t = (unsigned char *) s;
	while (n > 0)
	{
		t[i] = c;
		i++;
		n--;
	}
	return (s);
}

t_move_cost	find_min_pattern_cost(t_calc_params *params)
{
	t_move_cost	best_cost_found;
	t_move_cost	current_pattern_cost;

	best_cost_found.total_cost = INT_MAX;
	current_pattern_cost = init_move_cost();
	calc_cost_p1(&current_pattern_cost, params);
	if (current_pattern_cost.total_cost < best_cost_found.total_cost)
		best_cost_found = current_pattern_cost;
	current_pattern_cost = init_move_cost();
	calc_cost_p2(&current_pattern_cost, params);
	if (current_pattern_cost.total_cost < best_cost_found.total_cost)
		best_cost_found = current_pattern_cost;
	current_pattern_cost = init_move_cost();
	calc_cost_p3(&current_pattern_cost, params);
	if (current_pattern_cost.total_cost < best_cost_found.total_cost)
		best_cost_found = current_pattern_cost;
	current_pattern_cost = init_move_cost();
	calc_cost_p4(&current_pattern_cost, params);
	if (current_pattern_cost.total_cost < best_cost_found.total_cost)
		best_cost_found = current_pattern_cost;
	return (best_cost_found);
}

t_move_cost	calculate_cost_a_to_b(t_stack *a, t_stack *b,
			t_list *a_node_to_move)
{
	t_calc_params	calc_params;

	ft_memset(&calc_params, 0, sizeof(t_calc_params));
	calc_params.idx_a = get_node_index(a, a_node_to_move);
	calc_params.idx_b = find_insert_pos_in_b(b, a_node_to_move->content);
	calc_params.size_a = a->size;
	calc_params.size_b = b->size;
	return (find_min_pattern_cost(&calc_params));
}

// t_move_cost	calculate_cost_a_to_b(t_stack *a, t_stack *b,
// 				t_list *a_node_to_move)
// {
// 	t_move_cost		best_cost_found;
// 	t_move_cost		current_cost;
// 	t_calc_params	calc_params;

// 	ft_memset(&calc_params, 0, sizeof(t_calc_params));
// 	best_cost_found.total_cost = INT_MAX;
// 	calc_params.idx_a = get_node_index(a, a_node_to_move);
// 	calc_params.idx_b = find_insert_pos_in_b(b, a_node_to_move->content);
// 	calc_params.size_a = a->size;
// 	calc_params.size_b = b->size;
// 	current_cost = init_move_cost();
// 	calc_cost_p1(&current_cost, &calc_params);
// 	if (current_cost.total_cost < best_cost_found.total_cost)
// 		best_cost_found = current_cost;
// 	current_cost = init_move_cost();
// 	calc_cost_p2(&current_cost, &calc_params);
// 	if (current_cost.total_cost < best_cost_found.total_cost)
// 		best_cost_found = current_cost;
// 	current_cost = init_move_cost();
// 	calc_cost_p3(&current_cost, &calc_params);
// 	if (current_cost.total_cost < best_cost_found.total_cost)
// 		best_cost_found = current_cost;
// 	current_cost = init_move_cost();
// 	calc_cost_p4(&current_cost, &calc_params);
// 	if (current_cost.total_cost < best_cost_found.total_cost)
// 		best_cost_found = current_cost;
// 	return (best_cost_found);
// }
