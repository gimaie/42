/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_cost_pattern.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gimaie <gimaie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 15:59:35 by gimaie            #+#    #+#             */
/*   Updated: 2025/08/04 20:52:35 by gimaie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	calc_cost_p1(t_move_cost *cost_info, t_calc_params *params)
{
	cost_info->ra_moves = params->idx_a;
	cost_info->rb_moves = params->idx_b;
	cost_info->rra_moves = 0;
	cost_info->rrb_moves = 0;
	if (params->idx_a > params->idx_b)
		cost_info->total_cost = params->idx_a;
	else
		cost_info->total_cost = params->idx_b;
}

void	calc_cost_p2(t_move_cost *cost_info, t_calc_params *params)
{
	cost_info->ra_moves = 0;
	cost_info->rb_moves = 0;
	cost_info->rra_moves = calc_rot_moves(params->size_a, params->idx_a, 1);
	cost_info->rrb_moves = calc_rot_moves(params->size_b, params->idx_b, 1);
	if (cost_info->rra_moves > cost_info->rrb_moves)
		cost_info->total_cost = cost_info->rra_moves;
	else
		cost_info->total_cost = cost_info->rrb_moves;
}

void	calc_cost_p3(t_move_cost *cost_info, t_calc_params *params)
{
	cost_info->ra_moves = params->idx_a;
	cost_info->rb_moves = 0;
	cost_info->rra_moves = 0;
	cost_info->rrb_moves = calc_rot_moves(params->size_b, params->idx_b, 1);
	cost_info->total_cost = cost_info->ra_moves + cost_info->rrb_moves;
}

void	calc_cost_p4(t_move_cost *cost_info, t_calc_params *params)
{
	cost_info->ra_moves = 0;
	cost_info->rb_moves = params->idx_b;
	cost_info->rra_moves = calc_rot_moves(params->size_a, params->idx_a, 1);
	cost_info->rrb_moves = 0;
	cost_info->total_cost = cost_info->rra_moves + cost_info->rb_moves;
}
