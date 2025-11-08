/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gen <gen@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/11 16:56:11 by gen               #+#    #+#             */
/*   Updated: 2025/10/28 17:02:01 by gen              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	cleanup_game(t_game *game)
{
	if (game->wall_img)
		mlx_destroy_image(game->mlx, game->wall_img);
	if (game->player_img)
		mlx_destroy_image(game->mlx, game->player_img);
	if (game->exit_img)
		mlx_destroy_image(game->mlx, game->exit_img);
	if (game->collect_img)
		mlx_destroy_image(game->mlx, game->collect_img);
	if (game->floor_img)
		mlx_destroy_image(game->mlx, game->floor_img);
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
	if (game->map != NULL)
		free_array_and_return(game->map);
}
