#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <readline/readline.h>
#include <readline/history.h>
#include "minishell.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

static size_t	ft_strnlen(const char *s, size_t len)
{
	size_t	i;

	i = 0;
	while (s[i] && i < len)
		i++;
	return (i);
}

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	slen;
	size_t	dlen;

	slen = ft_strlen(src);
	dlen = ft_strnlen(dst, size);
	i = 0;
	if (size <= dlen)
		return (size + slen);
	while (src[i] && i + dlen < size - 1)
	{
		dst[dlen + i] = src[i];
		i++;
	}
	dst[dlen + i] = '\0';
	return (dlen + slen);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size != 0)
	{
		while (i < size - 1 && src[i])
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (ft_strlen(src));
}

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
