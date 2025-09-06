/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gimaie <gimaie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 17:10:36 by gimaie            #+#    #+#             */
/*   Updated: 2025/08/29 17:28:42 by gimaie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static size_t	ft_count_words_tab(char const *s, char c1, char c2)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] == c1 ||s[i] == c2)
			i++;
		if (s[i])
		{
			count++;
			while ((s[i] && s[i] != c1) && (s[i] && s[i] != c2))
				i++;
		}
	}
	return (count);
}

static char	**free_and_null(char **r, size_t filled)
{
	size_t	i;

	i = 0;
	while (i < filled)
	{
		free(r[i]);
		i++;
	}
	free(r);
	return (NULL);
}

/*
 * start から len 文字分だけ s からコピーして
 * ヌル終端した新しい文字列を返す。
 */
static char	*ft_copy_word(const char *s, size_t start, size_t len)
{
	char	*word;
	size_t	j;

	word = malloc(len + 1);
	if (word == NULL)
		return (NULL);
	j = 0;
	while (j < len)
	{
		word[j] = s[start + j];
		j++;
	}
	word[j] = '\0';
	return (word);
}

/*
 * s を区切り文字 c で分割し、
 * 事前に malloc された配列 r[count+1] に
 * 単語を順に詰めて最後を NULL 終端する。
 */
static char	**ft_extract_word(char const *s, char c1, char c2, char **r, size_t count)
{
	size_t	i;
	size_t	start;
	size_t	len;
	size_t	idx;

	i = 0;
	idx = 0;
	while (s[i] && idx < count)
	{
		while ((s[i] == c1) || (s[i] == c2))
			i++;
		start = i;
		while (s[i] && ((s[i] != c1) && (s[i] != c2)))
			i++;
		len = i - start;
		r[idx] = ft_copy_word(s, start, len);
		if (r[idx] == NULL)
			return (free_and_null(r, idx));
		idx++;
	}
	r[idx] = NULL;
	return (r);
}

char	**ft_split_space_tab(char const *s, char c1, char c2)
{
	size_t	count;
	char	**r;

	if (s == NULL)
		return (NULL);
	count = ft_count_words_tab(s, c1, c2);
	r = malloc((sizeof (char *)) * (count + 1));
	if (r == NULL)
		return (NULL);
	return (ft_extract_word(s, c1, c2, r, count));
}
