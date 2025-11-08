/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gen <gen@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 14:10:54 by gen               #+#    #+#             */
/*   Updated: 2025/10/16 15:44:07 by gen              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	init_mlx(t_game *game)
{
	game->mlx = mlx_init();
	if (game->mlx == NULL)
		return (0);
	game->win = mlx_new_window(game->mlx, game->width * TILE_SIZE,
			game->height * TILE_SIZE, "so_long");
	if (game->win == NULL)
		return (0);
	return (1);
}

int	load_textures(t_game *game)
{
	int	width;
	int	height;

	game->wall_img = mlx_xpm_file_to_image(game->mlx,
			"./textures/wall.xpm", &width, &height);
	game->player_img = mlx_xpm_file_to_image(game->mlx,
			"./textures/player.xpm", &width, &height);
	game->exit_img = mlx_xpm_file_to_image(game->mlx,
			"./textures/exit.xpm", &width, &height);
	game->collect_img = mlx_xpm_file_to_image(game->mlx,
			"./textures/collectible.xpm", &width, &height);
	game->floor_img = mlx_xpm_file_to_image(game->mlx,
			"./textures/floor.xpm", &width, &height);
	if (game->wall_img == NULL || game->player_img == NULL
		|| game->exit_img == NULL || game->collect_img == NULL
		|| game->floor_img == NULL)
	{
		return (0);
	}
	return (1);
}
