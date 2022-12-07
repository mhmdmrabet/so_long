/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmrabet <mmrabet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 19:31:12 by mmrabet           #+#    #+#             */
/*   Updated: 2022/11/28 19:31:12 by mmrabet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include "./../get_next_line/get_next_line.h"
# include "./../ft_printf/ft_printf.h"
# include "./../libft/libft.h"
# include "./../minilibx-linux/mlx.h"

# define WINDOW_WIDTH 600
# define WINDOW_HEIGHT 300

# define MLX_ERROR 1

typedef struct s_sprites
{
	void	*wall;
	void	*floor;
	void	*perso;
	void	*exit;
	void	*coin;
}	t_sprites;

typedef struct s_data_mlx
{
	void		*ptr;
	void		*win_ptr;
	t_sprites	sprites;
	int			i;
	int			j;
	int			x;
	int			y;
	int			height;
	int			width;
	int			nb_movement;
}	t_data_mlx;

typedef struct s_map_info
{
	char	**map;
	char	**map_cpy;
	int		len_map;
	int		map_p_index;
	int		line_p_index;
	int		exit_position_horizontal;
	int		exit_position_vertical;
	int		len_line;
	int		current_position_horizontal;
	int		current_position_vertical;
	int		prev_current_position_horizontal;
	int		prev_current_position_vertical;
	int		nb_items_collected;
	int		nb_items;
}	t_map_info;

typedef struct s_all_data
{
	t_data_mlx	*data;
	t_map_info	*map;
}	t_all_data;

int		isnt_obstacle(t_map_info *data, char search, int i, int j);
int		ft_find_depart_vert_position(char *line, t_map_info *data);
int		ft_find_depart_horizontal_position(t_map_info *data);
int		check_e_around_elmnt(t_map_info *data, int i, int j);
int		display_game(t_data_mlx *data, t_map_info *map);
int		ft_check_map(char *pathname, t_map_info *data);
int		ft_fill_map(char *pathname, t_map_info *data);
int		handle_keypress(int keysym, t_all_data *data);
int		ft_map_has_all_needed(t_map_info *data);
int		display_sprites(t_all_data *all_data);
int		ft_is_border_map_ok(t_map_info *data);
int		ft_is_rectangle_map(t_map_info *data);
int		check_format_file(char *pathname);
int		ft_is_wall_top_bottom(char *line);
int		is_path_valid(t_map_info *data);
int		ft_find_path(t_map_info *data);
int		ft_count_line(char *pathname);
int		ft_is_border_wall(char *line);
int		ft_is_characters(char c);
void	display_sprites_in_screen_y(t_data_mlx *data, t_map_info *map, int y, int x);
void	check_and_replace(t_map_info *data, int i, int j, int *add_x);
void	display_sprites_in_screen(t_data_mlx *data, t_map_info *map);
void	calcul_width_height(t_data_mlx *data, t_map_info *map);
void	move_to(char direction, t_all_data *data);
int		destroy_free_win(t_all_data *data);
void	ft_print_map_cpy(t_map_info *data);
void	move_bottom(t_all_data *all_data);
void	move_right(t_all_data *all_data);
void	create_sprites(t_data_mlx *data);
void	move_left(t_all_data *all_data);
void	ft_print_map(t_map_info *data);
void	move_top(t_all_data *all_data);
void	free_map(char **map, int size);
void	ft_parsing(int fd);
void	init_games(t_data_mlx *data, t_map_info *map);

#endif