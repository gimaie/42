/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   botton.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gen <gen@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 16:34:10 by gen               #+#    #+#             */
/*   Updated: 2025/10/17 16:34:29 by gen              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	wpush(t_game *game)
{
	if (game->map[game->player_y - 1][game->player_x] != '1')
	{
		if (game->map[game->player_y - 1][game->player_x] == 'C')
			when_collective(game, game->player_y - 1, game->player_x);
		if (game->map[game->player_y - 1][game->player_x] == 'E')
			when_exit(game);
		game->player_y--;
		game->moves++;
		ft_printf("movements :%i\n", game->moves);
		render_map(game);
	}
}

void	spush(t_game *game)
{
	if (game->map[game->player_y + 1][game->player_x] != '1')
	{
		if (game->map[game->player_y + 1][game->player_x] == 'C')
			when_collective(game, game->player_y + 1, game->player_x);
		if (game->map[game->player_y + 1][game->player_x] == 'E')
			when_exit(game);
		game->player_y++;
		game->moves++;
		ft_printf("movements :%i\n", game->moves);
		render_map(game);
	}
}

void	apush(t_game *game)
{
	if (game->map[game->player_y][game->player_x - 1] != '1')
	{
		if (game->map[game->player_y][game->player_x - 1] == 'C')
			when_collective(game, game->player_y, game->player_x - 1);
		if (game->map[game->player_y][game->player_x - 1] == 'E')
			when_exit(game);
		game->player_x--;
		game->moves++;
		ft_printf("movements :%i\n", game->moves);
		render_map(game);
	}
}

void	dpush(t_game *game)
{
	if (game->map[game->player_y][game->player_x + 1] != '1')
	{
		if (game->map[game->player_y][game->player_x + 1] == 'C')
			when_collective(game, game->player_y, game->player_x + 1);
		if (game->map[game->player_y][game->player_x + 1] == 'E')
			when_exit(game);
		game->player_x++;
		game->moves++;
		ft_printf("movements :%i\n", game->moves);
		render_map(game);
	}
}
