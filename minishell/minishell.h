#ifndef MINISHELL_H
# define MINISHELL_H

size_t	ft_strlcat(char *dst, const char *src, size_t size);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
char	**free_and_null(char **r, size_t filled);
char	**ft_extract_word(char const *s, char c, char **r, size_t count);
char	**ft_split(char const *s, char c);
size_t	ft_strlen(const char *s);
int    execution(char *line);

typedef struct s_cmd
{
	char			**args;
	int				fd_in;
	int				fd_out;
	struct s_cmd	*next;
}	t_cmd;

#endif
