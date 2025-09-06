/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gimaie <gimaie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 09:40:44 by gimaie            #+#    #+#             */
/*   Updated: 2025/05/08 10:33:00 by gimaie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_count_words(char const *s, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i])
		{
			count++;
			while (s[i] && s[i] != c)
				i++;
		}
	}
	return (count);
}

char	**free_and_null(char **r, size_t filled)
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
char	**ft_extract_word(char const *s, char c, char **r, size_t count)
{
	size_t	i;
	size_t	start;
	size_t	len;
	size_t	idx;

	i = 0;
	idx = 0;
	while (s[i] && idx < count)
	{
		while (s[i] == c)
			i++;
		start = i;
		while (s[i] && s[i] != c)
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

char	**ft_split(char const *s, char c)
{
	size_t	count;
	char	**r;

	if (s == NULL)
		return (NULL);
	count = ft_count_words(s, c);
	r = malloc((sizeof (char *)) * (count + 1));
	if (r == NULL)
		return (NULL);
	return (ft_extract_word(s, c, r, count));
}

// 1.区切り文字で分けられた単語数を数える。
// ２．その単語分のポインタ配列を確保する。
// ３．単語ごとに長さを数え、その長さ＋ヌル文字＋区切り文字マロックr[i][]する。
// ４．単語ごとにstrcpyでｒ配列に格納する。＋ヌル文字＋区切り文字つけて次の行

// int	main(void)
// {
// 	char	*cases[] = {
// 		"Hello world 42Tokyo",
// 		"",                /* empty */
// 		"   foo   bar  ",  /* leading/trailing/multi spaces */
// 		"abc",             /* no delimiter */
// 		NULL
// 	};
// 	char	**tokens;
// 	size_t	i;
// 	size_t	j;

// 	i = 0;
// 	while (cases[i])
// 	{
// 		printf("Case %zu: \"%s\"\n", i, cases[i]);
// 		tokens = ft_split(cases[i], ' ');
// 		if (tokens == NULL)
// 		{
// 			printf("  → NULL\n");
// 			i++;
// 			continue ;
// 		}
// 		j = 0;
// 		while (tokens[j])
// 		{
// 			printf("  [%zu] -> \"%s\"\n", j, tokens[j]);
// 			free(tokens[j]);
// 			j++;
// 		}
// 		free(tokens);
// 		i++;
// 	}
// 	return (0);
// }
