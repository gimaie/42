/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gimaie <gimaie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 10:11:05 by gimaie            #+#    #+#             */
/*   Updated: 2025/06/11 18:41:44 by gimaie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*now;
	t_list	*next_node;

	if (lst == NULL || del == NULL)
		return ;
	now = *lst;
	while (now != NULL)
	{
		next_node = now->next;
		del(now->content);
		free(now);
		now = next_node;
	}
	*lst = NULL;
}
