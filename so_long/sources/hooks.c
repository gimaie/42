/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gen <gen@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 15:30:45 by gen               #+#    #+#             */
/*   Updated: 2025/10/17 16:50:00 by gen              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	handle_keypress(int key_code, t_game *game)
{
	if (game == NULL)
		return (0);
	if (key_code == 65307)
	{
		cleanup_game(game);
		exit(0);
	}
	if (key_code == 119)
		wpush(game);
	if (key_code == 115)
		spush(game);
	if (key_code == 97)
		apush(game);
	if (key_code == 100)
		dpush(game);
	return (0);
}

int	handle_close_window(t_game *game)
{
	cleanup_game(game);
	exit(0);
	return (0);
}

void	when_collective(t_game *game, int y, int x)
{
	game->collectibles--;
	game->map[y][x] = '0';
	return ;
}

void	when_exit(t_game *game)
{
	if (game->collectibles == 0)
	{
		ft_printf("Congratulations!! CLEAR!!\n");
		cleanup_game(game);
		exit(0);
	}
}
