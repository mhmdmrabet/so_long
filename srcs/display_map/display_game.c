/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_game.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abchaban <abchaban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 14:44:30 by abchaban          #+#    #+#             */
/*   Updated: 2022/12/15 10:25:32 by abchaban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../so_long.h"

void	init_games(t_data_mlx *data, t_map_info *map)
{
	data->x = 0;
	data->y = 0;
	data->sprites.wall = NULL;
	data->sprites.floor = NULL;
	data->sprites.perso = NULL;
	data->sprites.exit = NULL;
	data->sprites.coin = NULL;
	map->map_cpy = NULL;
	map->map = NULL;
}

void	create_sprites(t_data_mlx *data)
{
	int	img_width;
	int	img_height;

	data->sprites.wall = mlx_xpm_file_to_image(data->ptr,
			"wall.xpm", &img_width, &img_height);
	data->sprites.floor = mlx_xpm_file_to_image(data->ptr,
			"floor2.xpm", &img_width, &img_height);
	data->sprites.perso = mlx_xpm_file_to_image(data->ptr,
			"perso.xpm", &img_width, &img_height);
	data->sprites.exit = mlx_xpm_file_to_image(data->ptr,
			"exit.xpm", &img_width, &img_height);
	data->sprites.coin = mlx_xpm_file_to_image(data->ptr,
			"coin.xpm", &img_width, &img_height);
}

void	display_sprites_in_screen_y(t_data_mlx *d, t_map_info *m, int y, int x)
{
	if (m->map_cpy[y][x] == '1')
		mlx_put_image_to_window(d->ptr,
			d->win_ptr, d->sprites.wall, x * 60, y * 60);
	else if (m->map_cpy[y][x] == '0')
		mlx_put_image_to_window(d->ptr,
			d->win_ptr, d->sprites.floor, x * 60, y * 60);
	else if (m->map_cpy[y][x] == 'P')
		mlx_put_image_to_window(d->ptr,
			d->win_ptr, d->sprites.perso, x * 60, y * 60);
	else if (m->map_cpy[y][x] == 'E')
		mlx_put_image_to_window(d->ptr,
			d->win_ptr, d->sprites.exit, x * 60, y * 60);
	else if (m->map_cpy[y][x] == 'C')
		mlx_put_image_to_window(d->ptr,
			d->win_ptr, d->sprites.coin, x * 60, y * 60);
}

int	display_sprites(t_all_data *all_data)
{
	int	y;
	int	x;

	y = 0;
	while (all_data->map->map_cpy[y])
	{
		x = 0;
		while (all_data->map->map_cpy[y][x])
		{
			display_sprites_in_screen_y(all_data->data, all_data->map, y, x);
			x++;
		}
		y++;
	}
	return (0);
}

int	display_game(t_data_mlx *data, t_map_info *map)
{
	t_all_data	all_data;

	map->nb_items_collected = 0;
	data->nb_movement = 1;
	all_data.data = data;
	all_data.map = map;
	all_data.map->on_exit = 0;
	calcul_width_height(data, map);
	data->win_ptr = mlx_new_window(data->ptr,
			data->i, data->j, "SO_LONG");
	if (data->win_ptr == NULL)
		return (free(data->ptr), MLX_ERROR);
	create_sprites(data);
	mlx_hook(data->win_ptr, Expose, ExposureMask, display_sprites, &all_data);
	mlx_hook(data->win_ptr, DestroyNotify, KeyPressMask,
		destroy_free_win, &all_data);
	mlx_hook(data->win_ptr, KeyPress, KeyPressMask, &handle_keypress,
		&all_data);
	mlx_loop(data->ptr);
	free_sprites(&all_data);
	return (0);
}
