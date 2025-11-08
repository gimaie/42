/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gen <gen@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 11:09:13 by gen               #+#    #+#             */
/*   Updated: 2025/10/17 14:59:04 by gen              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	render_map(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->height)
	{
		x = 0;
		while (x < game->width)
		{
			if (!choose_pic(game, x, y))
				return (0);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(game->mlx, game->win, game->player_img,
		game->player_x * TILE_SIZE, game->player_y * TILE_SIZE);
	return (1);
}

int	choose_pic(t_game *game, int x, int y)
{
	if (game->map[y][x] == '1')
		mlx_put_image_to_window(game->mlx, game->win,
			game->wall_img, x * TILE_SIZE, y * TILE_SIZE);
	else if (game->map[y][x] == '0' || game->map[y][x] == 'P')
		mlx_put_image_to_window(game->mlx, game->win, game->floor_img,
			x * TILE_SIZE, y * TILE_SIZE);
	else if (game->map[y][x] == 'C')
		mlx_put_image_to_window(game->mlx, game->win, game->collect_img,
			x * TILE_SIZE, y * TILE_SIZE);
	else if (game->map[y][x] == 'E')
		mlx_put_image_to_window(game->mlx, game->win, game->exit_img,
			x * TILE_SIZE, y * TILE_SIZE);
	else
		return (0);
	return (1);
}
