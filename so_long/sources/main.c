/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gen <gen@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 16:17:22 by gen               #+#    #+#             */
/*   Updated: 2025/10/28 16:18:15 by gen              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	check_argv(int argc, char **argv)
{
	const char	*dot;

	if (argc != 2)
		return (0);
	dot = ft_strrchr(argv[1], '.');
	if (dot == NULL || ft_strcmp(dot, ".ber") != 0)
		return (0);
	return (1);
}

int	main(int argc, char **argv)
{
	t_game	game;

	ft_bzero(&game, sizeof(t_game));
	if (start_validation(argc, argv, &game) == 1)
	{
		if (init_mlx(&game) == 1)
		{
			if (load_textures(&game) == 0)
			{
				ft_printf("Error\n");
				cleanup_game(&game);
				return (1);
			}
			mlx_key_hook(game.win, handle_keypress, &game);
			mlx_hook(game.win, 17, 0, handle_close_window, &game);
			mlx_loop_hook(game.mlx, render_map, &game);
			mlx_loop(game.mlx);
		}
	}
	else
		ft_printf("Error\n");
	cleanup_game(&game);
	return (0);
}

//int	main(void)
//{
//	void	*mlx_ptr;
//	void	*win_ptr;

//	mlx_ptr = mlx_init();
//	win_ptr = mlx_new_window(mlx_ptr, 500, 500, "mlx 42");
//	mlx_loop(mlx_ptr);
//}
