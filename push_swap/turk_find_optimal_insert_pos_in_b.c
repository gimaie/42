/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_find_optimal_insert_pos_in_b.c                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gimaie <gimaie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 14:08:35 by gimaie            #+#    #+#             */
/*   Updated: 2025/08/06 09:38:47 by gimaie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_insert_pos_in_b(t_stack *b, int value_from_a)
{
	int		initial_check_done;
	t_list	*current;
	t_list	*max_node;
	t_list	*min_node;

	if (b == NULL || b->head == NULL || b->size == 0)
		return (0);
	max_node = get_max_node(b);
	min_node = get_min_node(b);
	if (value_from_a > max_node->content || value_from_a < min_node->content)
		return (get_node_index(b, min_node));
	current = b->head;
	initial_check_done = 0;
	while (current != b->head || initial_check_done == 0)
	{
		initial_check_done = 1;
		if (value_from_a < current->content
			&& value_from_a > current->next->content)
			return (get_node_index(b, current->next));
		current = current->next;
	}
	return (-1);
}

t_list	*get_min_node(t_stack *b)
{
	int		min;
	t_list	*current;
	t_list	*min_node;

	if (b == NULL || b->head == NULL || b->size == 0)
		return (NULL);
	current = b->head;
	min = current->content;
	min_node = current;
	current = current->next;
	while (current != b->head)
	{
		if (min >= current->content)
		{
			min = current->content;
			min_node = current;
		}
		current = current->next;
	}
	return (min_node);
}

t_list	*get_max_node(t_stack *b)
{
	int		max;
	t_list	*current;
	t_list	*max_node;

	if (b == NULL || b->head == NULL || b->size == 0)
		return (NULL);
	current = b->head;
	max = current->content;
	max_node = current;
	current = current->next;
	while (current != b->head)
	{
		if (max <= current->content)
		{
			max = current->content;
			max_node = current;
		}
		current = current->next;
	}
	return (max_node);
}

int	get_node_index(t_stack *stack, t_list *target_list)
{
	int		i;
	int		initial_check_done;
	t_list	*current;

	current = stack->head;
	i = 0;
	initial_check_done = 1;
	while (current != stack->head || initial_check_done)
	{
		initial_check_done = 0;
		if (current == target_list)
			return (i);
		current = current->next;
		i++;
	}
	return (-1);
}
