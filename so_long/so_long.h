/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gen <gen@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 20:09:15 by gen               #+#    #+#             */
/*   Updated: 2025/10/26 20:09:15 by gen              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./libft/libft.h"
# include "./get_next_line/get_next_line.h"
# include "./ft_printf/ft_printf.h"
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <fcntl.h>
# include "./minilibx-linux/mlx.h"

# define TILE_SIZE 32

typedef void	*t_mlx_ptr;
typedef void	*t_win_ptr;

typedef struct s_game
{
	char		**map;
	int			width;
	int			height;
	t_mlx_ptr	mlx;
	t_win_ptr	win;
	int			player_x;
	int			player_y;
	int			collectibles;
	int			moves;
	void		*wall_img;
	void		*player_img;
	void		*exit_img;
	void		*collect_img;
	void		*floor_img;
}	t_game;

typedef struct s_counts
{
	int	players;
	int	exits;
	int	collectibles;
	int	x;
	int	y;
}	t_counts;

int		check_argv(int argc, char **argv);
int		line_to_list(char *line, t_list **head);
t_list	*read_map(char **argv);
char	**list_to_array(t_list *head);
int		val_rectangular(t_game *game);
int		val_wall(t_game *game);
int		check_pec01(char c, t_counts *counts, t_game *game);
int		validate_components(t_game *game);
char	**copy_map(t_game *game);
void	flood_fill(t_game *game, char **map_copy, int y, int x);
int		check_flood(t_game *game, char **map_copy);
int		validate_static_map(t_game *game);
void	free_map_copy(char **map_copy);
int		validate_path(t_game *game);
void	init_game_struct(t_game *game);
int		start_validation(int argc, char **argv, t_game *game);
void	cleanup_game(t_game *game);
int		init_mlx(t_game *game);
int		load_textures(t_game *game);
int		handle_keypress(int key_code, t_game *game);
int		handle_close_window(t_game *game);
void	wpush(t_game *game);
void	spush(t_game *game);
void	apush(t_game *game);
void	dpush(t_game *game);
void	when_collective(t_game *game, int y, int x);
void	when_exit(t_game *game);
int		choose_pic(t_game *game, int x, int y);
int		render_map(t_game *game);
int		ft_strcmp(const char *s1, const char *s2);
char	**free_array_and_return(char **array);
int		main(int argc, char **argv);
#endif
