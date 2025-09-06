/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_list_and_stack.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gimaie <gimaie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 10:55:36 by gimaie            #+#    #+#             */
/*   Updated: 2025/08/06 19:42:17 by gimaie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*create_last_node(t_list *head, int *ns, int size)
{
	t_list	*current;
	t_list	*new_node;
	int		i;

	if (size <= 1)
		return (head);
	current = head;
	i = 1;
	while (i < size)
	{
		new_node = ft_lstnew_prev(&ns[i], current);
		if (!new_node)
		{
			ft_free_list(head);
			return (NULL);
		}
		current->next = new_node;
		current = new_node;
		i++;
	}
	return (current);
}

t_list	*make_list(int *ns, int size)
{
	t_list	*head;
	t_list	*last_node;

	if (ns == NULL || size <= 0)
		return (NULL);
	head = ft_lst_head(&ns[0]);
	if (head == NULL)
	{
		free(ns);
		return (NULL);
	}
	last_node = create_last_node(head, ns, size);
	if (last_node == NULL)
	{
		free(ns);
		return (NULL);
	}
	if (size > 1)
	{
		last_node->next = head;
		head->prev = last_node;
	}
	free(ns);
	return (head);
}

t_stack	*assign_stack(t_list *list_head, int size)
{
	t_stack	*stack;
	t_list	*current;

	stack = malloc(sizeof(t_stack));
	if (stack == NULL)
		return (NULL);
	stack->head = list_head;
	stack->size = size;
	current = list_head;
	while (current->next != list_head)
		current = current->next;
	stack->bottom = current;
	return (stack);
}

t_stack	*make_stack_a(int *ns, int size)
{
	t_list	*head_a;
	t_stack	*a;

	head_a = make_list(ns, size);
	if (head_a == NULL)
		return (NULL);
	a = assign_stack(head_a, size);
	if (a == NULL)
	{
		ft_free_list(head_a);
		return (NULL);
	}
	return (a);
}

t_stack	*make_stack_b(t_stack *a)
{
	t_stack	*b;

	if (a == NULL)
		return (NULL);
	b = malloc(sizeof(t_stack));
	if (b == NULL)
	{
		free_stack(a);
		return (NULL);
	}
	b->head = NULL;
	b->bottom = NULL;
	b->size = 0;
	return (b);
}

// t_list	*make_list(int *ns, int size)
// {
// 	int		i;
// 	t_list	*current;
// 	t_list	*head;
// 	t_list	*new;

// 	if (ns == NULL || size <= 0)
// 		return (NULL);
// 	head = ft_lst_head(&ns[0]);
// 	current = head;
// 	i = 1;
// 	while (i < size)
// 	{
// 		new = ft_lstnew_prev(&ns[i], current);
// 		if (!new)
// 		{
// 			ft_free_list(head);
// 			return (NULL);
// 		}
// 		current->next = new;
// 		current = new;
// 		i++;
// 	}
// 	if (size > 1)
// 	{
// 		current->next = head;
// 		head->prev = current;
// 	}
// 	free(ns);
// 	return (head);
// }
