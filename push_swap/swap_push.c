/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_push.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gimaie <gimaie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 13:18:39 by gimaie            #+#    #+#             */
/*   Updated: 2025/08/06 17:37:12 by gimaie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack *stack)
{
	t_list	*first;
	t_list	*second;
	t_list	*third;
	t_list	*last;

	if (stack == NULL || stack->size < 2)
		return ;
	first = stack->head;
	second = first->next;
	last = stack->bottom;
	if (stack->size == 2)
	{
		stack->head = second;
		stack->bottom = first;
		return ;
	}
	third = second->next;
	stack->head = second;
	second->next = first;
	first->prev = second;
	first->next = third;
	third->prev = first;
	last->next = second;
	second->prev = last;
}

// void	swap(t_stack *stack)
// {
// 	t_list	*first;
// 	t_list	*second;

// 	if (stack == NULL || stack->size < 2)
// 		return ;
// 	first = stack->head;
// 	second = first->next;
// 	first->next = second->next;
// 	if (second->next != NULL)
// 		second->next->prev = first;
// 	second->next = first;
// 	first->prev = second;
// 	second->prev = NULL;
// 	stack->head = second;
// 	if (stack->size == 2)
// 		stack->bottom = first;
// }

static void	detach_from_stack(t_stack *stack)
{
	t_list	*node_to_detach;

	node_to_detach = stack->head;
	if (stack->size > 1)
	{
		stack->head = node_to_detach->next;
		stack->bottom->next = stack->head;
		stack->head->prev = stack->bottom;
	}
	else
	{
		stack->head = NULL;
		stack->bottom = NULL;
	}
}

void	push(t_stack *from, t_stack *to)
{
	t_list	*node_to_move;

	if (from == NULL || from->size < 1)
		return ;
	node_to_move = from->head;
	detach_from_stack(from);
	if (to->size == 0)
	{
		to->head = node_to_move;
		to->bottom = node_to_move;
		node_to_move->next = node_to_move;
		node_to_move->prev = node_to_move;
	}
	else
	{
		to->head->prev = node_to_move;
		node_to_move->next = to->head;
		node_to_move->prev = to->bottom;
		to->bottom->next = node_to_move;
		to->head = node_to_move;
	}
	from->size--;
	to->size++;
}

void	rotate(t_stack *stack)
{
	t_list	*old_head;

	if (stack == NULL || stack->size < 2)
		return ;
	old_head = stack->head;
	stack->head = old_head->next;
	stack->bottom = old_head;
}

void	reverse_rotate(t_stack *stack)
{
	t_list	*old_bottom;

	if (stack == NULL || stack->size < 2)
		return ;
	old_bottom = stack->bottom;
	stack->head = old_bottom;
	stack->bottom = old_bottom->prev;
}

// void	push_old(t_stack *from, t_stack *to)
// {
// 	t_list	*node_to_move;

// 	if (from == NULL || from->size < 1)
// 		return ;
// 	node_to_move = from->head;
// 	from->head = node_to_move->next;
// 	if (from->head != NULL)
// 		from->head->prev = NULL;
// 	else
// 		from->bottom = NULL;
// 	node_to_move->next = NULL;
// 	node_to_move->prev = NULL;
// 	if (to->size == 0)
// 	{
// 		to->head = node_to_move;
// 		to->bottom = node_to_move;
// 	}
// 	else
// 	{
// 		to->head->prev = node_to_move;
// 		node_to_move->next = to->head;
// 		to->head = node_to_move;
// 	}
// 	from->size--;
// 	to->size++;
// }
