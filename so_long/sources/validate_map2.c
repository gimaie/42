/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gen <gen@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/11 16:03:45 by gen               #+#    #+#             */
/*   Updated: 2025/10/28 17:01:04 by gen              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	check_pec01(char c, t_counts *counts, t_game *game)
{
	if (c == 'P')
	{
		counts->players++;
		game->player_x = counts->x;
		game->player_y = counts->y;
	}
	else if (c == 'E')
		counts->exits++;
	else if (c == 'C')
		counts->collectibles++;
	else if (c != '0' && c != '1')
		return (0);
	return (1);
}

int	validate_components(t_game *game)
{
	t_counts	counts;

	counts.players = 0;
	counts.exits = 0;
	counts.collectibles = 0;
	counts.y = 0;
	while (counts.y < game->height)
	{
		counts.x = 0;
		while (counts.x < game ->width)
		{
			if (!check_pec01(game->map[counts.y][counts.x], &counts, game))
				return (0);
			counts.x++;
		}
		counts.y++;
	}
	game->collectibles = counts.collectibles;
	if (counts.players == 1 && counts.exits == 1 && counts.collectibles >= 1)
		return (1);
	return (0);
}

char	**copy_map(t_game *game)
{
	char	**copied_map;
	int		i;

	if (game->map == NULL)
		return (NULL);
	copied_map = malloc(sizeof(char *) * (game->height + 1));
	if (copied_map == NULL)
		return (NULL);
	i = 0;
	while (i < game->height)
	{
		copied_map[i] = ft_strdup(game->map[i]);
		if (copied_map[i] == NULL)
			return (free_array_and_return(copied_map));
		i++;
	}
	copied_map[i] = NULL;
	return (copied_map);
}

void	flood_fill(t_game *game, char **map_copy, int y, int x)
{
	if (x < 0 || x >= game->width || y < 0 || y >= game ->height)
		return ;
	if (map_copy[y][x] == '1' || map_copy[y][x] == 'F')
		return ;
	map_copy[y][x] = 'F';
	flood_fill(game, map_copy, y + 1, x);
	flood_fill(game, map_copy, y - 1, x);
	flood_fill(game, map_copy, y, x + 1);
	flood_fill(game, map_copy, y, x - 1);
}

int	check_flood(t_game *game, char **map_copy)
{
	int	y;
	int	x;

	if (game == NULL || map_copy == NULL)
		return (0);
	y = 0;
	while (y < game->height)
	{
		x = 0;
		while (x < game->width)
		{
			if (map_copy[y][x] == 'C' || map_copy[y][x] == 'E')
				return (0);
			x++;
		}
		y++;
	}
	return (1);
}
