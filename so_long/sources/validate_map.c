/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 10:03:47 by marvin            #+#    #+#             */
/*   Updated: 2025/10/08 10:03:47 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	line_to_list(char *line, t_list **head)
{
	t_list	*next_node;
	char	*trimmed_line;

	trimmed_line = ft_strtrim(line, "\n");
	free(line);
	if (trimmed_line == NULL)
		return (0);
	next_node = ft_lstnew(trimmed_line);
	if (next_node == NULL)
	{
		free(trimmed_line);
		return (0);
	}
	ft_lstadd_back(head, next_node);
	return (1);
}

t_list	*read_map(char **argv)
{
	int		fd;
	char	*line;
	t_list	*head;

	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		return (NULL);
	head = NULL;
	line = get_next_line(fd);
	while (line != NULL)
	{
		if (!line_to_list(line, &head))
		{
			ft_lstclear(&head, free);
			close(fd);
			return (NULL);
		}
		line = get_next_line(fd);
	}
	close(fd);
	return (head);
}

char	**list_to_array(t_list *head)
{
	int		lst_size;
	int		i;
	char	**array;
	t_list	*current;

	if (head == NULL)
		return (NULL);
	lst_size = ft_lstsize(head);
	array = malloc(sizeof(char *) * (lst_size + 1));
	if (array == NULL)
		return (NULL);
	i = 0;
	current = head;
	while (current)
	{
		array[i] = ft_strdup((char *)current->content);
		if (array[i] == NULL)
			return (free_array_and_return(array));
		i++;
		current = current->next;
	}
	array[i] = NULL;
	return (array);
}

int	val_rectangular(t_game *game)
{
	int	y;
	int	first_row_width;

	if (game->map == NULL || game->map[0] == NULL)
		return (0);
	first_row_width = ft_strlen(game->map[0]);
	y = 0;
	while (game->map[y])
	{
		if ((int)ft_strlen(game->map[y]) != first_row_width)
			return (0);
		y++;
	}
	game->width = first_row_width;
	game->height = y;
	return (1);
}

int	val_wall(t_game *game)
{
	int	i;
	int	j;

	if (game->map == NULL)
		return (0);
	i = 0;
	while (i < game->height)
	{
		j = 0;
		while (j < game->width)
		{
			if (i == 0 || i == game->height -1
				|| j == 0 || j == game->width - 1)
			{
				if (game->map[i][j] != '1')
					return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

//t_list	*read_map(char **argv)
//{
//	int		fd;
//	char	*line;
//	t_list	*next_node;
//	t_list	*head;
//	char	*trimmed_line;

//	fd = open(argv[1], O_RDONLY);
//	if (fd < 0)
//		return (NULL);
//	head = NULL;
//	line = get_next_line(fd);
//	while (line != NULL)
//	{
//		trimmed_line = ft_strtrim(line, "\n");
//		free(line);
//		if (trimmed_line == NULL)
//		{
//			ft_lstclear(&head, free);
//			close(fd);
//			return (NULL);
//		}
//		next_node = ft_lstnew(trimmed_line);
//		if (next_node == NULL)
//		{
//			free(trimmed_line);
//			ft_lstclear(&head, free);
//			close(fd);
//			return (NULL);
//		}
//		ft_lstadd_back(&head, next_node);
//		line = get_next_line(fd);
//	}
//	close(fd);
//	return (head);
//}

//void	find_start(char **map_copy, t_game *game)
//{
//	int	x;
//	int	y;

//	if (map_copy == NULL || game == NULL)
//		return ;
//	y = 0;
//	while (y < game->height)
//	{
//		x = 0;
//		while (x < game->width)
//		{
//			if (map_copy[y][x] == 'P')
//			{
//				game->player_x = x;
//				game->player_y = y;
//				return ;
//			}
//			x++;
//		}
//		y++;
//	}
//	return ;
//}
