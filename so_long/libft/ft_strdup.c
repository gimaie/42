/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gimaie <gimaie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 16:37:45 by gimaie            #+#    #+#             */
/*   Updated: 2025/05/21 13:48:01 by gimaie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// char	*ft_strcpy(char *dest, const char *src)
// {
// 	char	*head;

// 	head = dest;
// 	while (*src)
// 	{
// 		*dest = *src;
// 		src++;
// 		dest++;
// 	}
// 	*dest = '\0';
// 	return (head);
// }
// // strcpyは最後終端文字入れる。

char	*ft_strdup(const char *s)
{
	size_t	len;
	char	*t;

	len = ft_strlen(s);
	t = malloc(len + 1);
	if (t == NULL)
		return (NULL);
	ft_strlcpy(t, s, (len + 1));
	return (t);
}
// int	main(void)
// {
// 	char *s = "aiueo";
// 	printf("%s", ft_strdup(s));
// }
