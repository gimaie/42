/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gimaie <gimaie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 11:06:39 by gimaie            #+#    #+#             */
/*   Updated: 2025/06/11 18:11:57 by gimaie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	free_list(t_list *lst, void (*del)(void *))
{
	t_list	*current;
	t_list	*next_node;

	if (lst == NULL || del == NULL)
		return ;
	current = lst;
	while (current != NULL)
	{
		next_node = current->next;
		del(current->content);
		free(current);
		current = next_node;
	}
}

static t_list	*create_node_safe(void *content, void (*del)(void *))
{
	t_list	*node;

	node = ft_lstnew(content);
	if (node == NULL)
		del(content);
	return (node);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*head;
	void	*content;

	if (lst == NULL || f == NULL || del == NULL)
		return (NULL);
	content = f(lst->content);
	head = create_node_safe(content, del);
	if (head == NULL)
		return (NULL);
	lst = lst->next;
	while (lst != NULL)
	{
		content = f(lst->content);
		new_list = create_node_safe(content, del);
		if (new_list == NULL)
		{
			free_list(head, del);
			return (NULL);
		}
		ft_lstadd_back(&head, new_list);
		lst = lst->next;
	}
	return (head);
}

// static void	free_list(t_list *new, void (*del)(void *))
// {
// 	t_list	*now;
// 	t_list	*next2;

// 	if (new == NULL || del == NULL)
// 		return ;
// 	now = new;
// 	while (now != NULL)
// 	{
// 		next2 = (*now).next;
// 		del((*now).content);
// 		free(now);
// 		now = next2;
// 	}
// }

// t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
// {
// 	t_list	*now;
// 	t_list	*new;
// 	t_list	*head;
// 	t_list	*last;

// 	head = NULL;
// 	last = NULL;
// 	if (lst == NULL || f == NULL)
// 		return (NULL);
// 	now = lst;
// 	while (now != NULL)
// 	{
// 		new = malloc(sizeof(t_list));
// 		if (new == NULL)
// 		{
// 			free_list(head, del);
// 			return (NULL);
// 		}
// 		(*new).content = f((*now).content);
// 		(*new).next = NULL;
// 		if (head == NULL)
// 			head = new;
// 		else
// 			(*last).next = new;
// 		last = new;
// 		now = (*now).next;
// 	}
// 	return (head);
// }
