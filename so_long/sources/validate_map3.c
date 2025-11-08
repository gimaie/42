/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gen <gen@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/11 16:04:13 by gen               #+#    #+#             */
/*   Updated: 2025/10/28 16:59:08 by gen              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	validate_static_map(t_game *game)
{
	if (!val_rectangular(game))
		return (0);
	if (!val_wall(game))
		return (0);
	if (!validate_components(game))
		return (0);
	return (1);
}

void	free_map_copy(char **map_copy)
{
	int	i;

	i = 0;
	while (map_copy[i] != NULL)
	{
		free(map_copy[i]);
		i++;
	}
	free(map_copy);
}

int	validate_path(t_game *game)
{
	char	**map_copy;
	int		fill_ok;

	map_copy = copy_map(game);
	if (map_copy == NULL)
		return (0);
	flood_fill(game, map_copy, game->player_y, game->player_x);
	fill_ok = check_flood(game, map_copy);
	free_map_copy(map_copy);
	return (fill_ok);
}

void	init_game_struct(t_game *game)
{
	game->map = NULL;
	game->width = 0;
	game->height = 0;
	game->mlx = NULL;
	game->win = NULL;
	game->player_x = 0;
	game->player_y = 0;
	game->collectibles = 0;
	game->moves = 0;
}

int	start_validation(int argc, char **argv, t_game *game)
{
	t_list	*head;

	if (!check_argv(argc, argv))
		return (0);
	init_game_struct(game);
	head = read_map(argv);
	if (head == NULL)
		return (0);
	game->map = list_to_array(head);
	ft_lstclear(&head, free);
	if (game->map == NULL)
		return (0);
	if (!validate_static_map(game))
	{
		return (0);
	}
	if (!validate_path(game))
	{
		return (0);
	}
	return (1);
}

//int	main(void)
//{
//	void	*mlx_ptr;
//	void	*win_ptr;
//	t_game	game;

//	init_game_struct(&game);
//	mlx_ptr = mlx_init();
//	win_ptr = mlx_new_window(mlx_ptr, 500, 500, "mlx 42");
//	mlx_loop(mlx_ptr);
//}
