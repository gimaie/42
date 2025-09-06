/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gimaie <gimaie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 15:20:01 by gimaie            #+#    #+#             */
/*   Updated: 2025/08/06 17:30:50 by gimaie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_lstnew_prev(int *content, t_list *prev)
{
	t_list	*node;

	node = malloc(sizeof(t_list));
	if (node == NULL)
		return (NULL);
	node->content = *content;
	node->next = NULL;
	node->prev = prev;
	return (node);
}

long	ft_atol(const char *nptr)
{
	int			sign;
	long		result;
	int			digit;
	const char	*p;

	sign = 1;
	result = 0;
	p = nptr;
	while (((*p >= '\t') && (*p <= '\r' )) || (*p == 32))
		p++;
	if (*p == '-' || *p == '+')
	{
		if (*p == '-')
			sign = sign * (-1);
		p++;
	}
	while (*p >= '0' && *p <= '9')
	{
		digit = *p - '0';
		result = result * 10 + digit;
		p++;
	}
	return (result * sign);
}

void	ft_free_list(t_list *lst)
{
	t_list	*current;
	t_list	*next_node;

	if (lst == NULL)
		return ;
	if (lst->next == lst)
	{
		free(lst);
		return ;
	}
	lst->prev->next = NULL;
	current = lst;
	while (current != NULL)
	{
		next_node = current->next;
		free(current);
		current = next_node;
	}
}

void	free_stack(t_stack *stack)
{
	if (stack == NULL)
		return ;
	ft_free_list(stack->head);
	free(stack);
}

t_list	*ft_lst_head(int *content)
{
	t_list	*node;

	node = malloc(sizeof(t_list));
	if (node == NULL)
		return (NULL);
	node->content = *content;
	node->next = node;
	node->prev = node;
	return (node);
}

// int	ft_atoi(const char *nptr)
// {
// 	int			sign;
// 	int			result;
// 	int			digit;
// 	const char	*p;

// 	sign = 1;
// 	result = 0;
// 	p = nptr;
// 	while (((*p >= '\t') && (*p <= '\r' )) || (*p == 32))
// 		p++;
// 	if (*p == '-' || *p == '+')
// 	{
// 		if (*p == '-')
// 			sign = sign * (-1);
// 		p++;
// 	}
// 	while (*p >= '0' && *p <= '9')
// 	{
// 		digit = *p - '0';
// 		result = result * 10 + digit;
// 		p++;
// 	}
// 	return (result * sign);
// }

// void	ft_free_list(t_list *lst)
// {
// 	t_list	*current;
// 	t_list	*next_node;
// 	t_list	*head;

// 	if (lst == NULL)
// 		return ;
// 	head = lst;
// 	current = lst->next;
// 	while (current != head)
// 	{
// 		next_node = current->next;
// 		free(current);
// 		current = next_node;
// 	}
// 	free(head);
// }
