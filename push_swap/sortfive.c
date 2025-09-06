/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortfive.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gimaie <gimaie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 20:08:03 by gimaie            #+#    #+#             */
/*   Updated: 2025/08/06 17:26:55 by gimaie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*get_min(t_list *head)
{
	t_list	*now;
	t_list	*min_list;
	int		min;
	int		head_check;

	now = head;
	min = head->content;
	min_list = head;
	head_check = 1;
	while (now != head || head_check == 1)
	{
		head_check = 0;
		if (min > now->content)
		{
			min = now->content;
			min_list = now;
		}
		now = now->next;
	}
	return (min_list);
}

int	where_min(t_stack *a)
{
	t_list	*min_list;
	t_list	*now;
	int		i;

	now = a->head;
	min_list = get_min(a->head);
	i = 0;
	while (now != min_list)
	{
		i++;
		now = now->next;
	}
	return (i);
}

void	min_to_b(t_stack *a, t_stack *b, int i)
{
	if (i <= 0)
		pb(a, b);
	else if (i == 1)
	{
		ra(a);
		pb(a, b);
	}
	else if (i == 2)
	{
		ra(a);
		ra(a);
		pb(a, b);
	}
	else if (i == 3)
	{
		ra(a);
		ra(a);
		ra(a);
		pb (a, b);
	}
	else if (i == 4)
	{
		rra(a);
		pb(a, b);
	}
}

void	sort_five(t_stack *a, t_stack *b, int n)
{
	int		i;

	if (n == 4)
	{
		i = where_min(a);
		min_to_b(a, b, i);
		sort_three(a);
		pa(b, a);
	}
	else if (n == 5)
	{
		i = where_min(a);
		min_to_b(a, b, i);
		i = where_min(a);
		min_to_b(a, b, i);
		sort_three(a);
		pa(b, a);
		pa(b, a);
	}
}
