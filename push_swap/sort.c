/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gimaie <gimaie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 17:31:22 by gimaie            #+#    #+#             */
/*   Updated: 2025/08/04 20:07:44 by gimaie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_stack(t_stack *a, t_stack *b)
{
	if (a->size == 2)
		sort_two(a);
	else if (a->size == 3)
		sort_three(a);
	else if (a->size <= 5)
		sort_five(a, b, a->size);
	else if (a->size >= 6)
		sort_turk(a, b);
}

void	sort_two(t_stack *stack)
{
	if (stack->head->content > stack->head->next->content)
		sa(stack);
}

void	sort_three(t_stack *stack)
{
	int	n1;
	int	n2;
	int	n3;

	n1 = stack->head->content;
	n2 = stack->head->next->content;
	n3 = stack->bottom->content;
	if (n1 < n3 && n3 < n2)
	{
		rra(stack);
		sa(stack);
	}
	else if (n2 < n1 && n1 < n3)
		sa(stack);
	else if (n3 < n1 && n1 < n2)
		rra(stack);
	else if (n2 < n3 && n3 < n1)
		ra(stack);
	else if (n3 < n2 && n2 < n1)
	{
		sa(stack);
		rra(stack);
	}
}
