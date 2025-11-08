/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gimaie <gimaie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 20:17:00 by gimaie            #+#    #+#             */
/*   Updated: 2025/05/03 18:15:40 by gimaie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len;
	char	*s;
	char	*head;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	s = malloc(len + 1);
	if (s == NULL)
		return (NULL);
	head = s;
	while (*s1)
	{
		*s = *s1;
		s++;
		s1++;
	}
	while (*s2)
	{
		*s = *s2;
		s++;
		s2++;
	}
	*s = '\0';
	return (head);
}

// int	main(void)
// {
// 	char const *s1 = "aiueo123";
// 	char const *s2 = "kstnhm";
// 	printf("%s", ft_strjoin(s1, s2));
// }
