/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gimaie <gimaie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 17:50:29 by gimaie            #+#    #+#             */
/*   Updated: 2025/05/08 10:19:01 by gimaie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	max;
	char	*t;
	size_t	slen;

	if (s == NULL)
		return (NULL);
	slen = ft_strlen(s);
	if (start >= slen)
		return (ft_strdup(""));
	max = slen - start;
	if (max > len)
		max = len;
	t = malloc(max + 1);
	if (t == NULL)
		return (NULL);
	i = 0;
	while (i < max && s[start])
	{
		t[i] = s[start];
		i++;
		start++;
	}
	t[i] = '\0';
	return (t);
}

// int	main (void)
// {
// 	const char		*s = "aiueokstnhmyrw";
// 	unsigned int	start = 5;
// 	size_t			len = 100;
// 	printf("%s", ft_substr(s, start, len));
// }
