/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_game.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abchaban <abchaban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 16:03:46 by abchaban          #+#    #+#             */
/*   Updated: 2022/12/06 16:51:16 by abchaban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../so_long.h"

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

void	display_sprites_in_screen_y(t_data_mlx *data, t_map_info *map)
{
	int		img_width;
	int		img_height;

	create_sprites(data);
	if (map->map_cpy[data->y][data->x] == '1')
		mlx_put_image_to_window(data->ptr,
			data->win_ptr, data->sprites.wall, data->x * 60, data->y * 60);
	else if (map->map_cpy[data->y][data->x] == '0')
		mlx_put_image_to_window(data->ptr,
			data->win_ptr, data->sprites.floor, data->x * 60, data->y * 60);
	else if (map->map_cpy[data->y][data->x] == 'P')
		mlx_put_image_to_window(data->ptr,
			data->win_ptr, data->sprites.perso, data->x * 60, data->y * 60);
	else if (map->map_cpy[data->y][data->x] == 'E')
		mlx_put_image_to_window(data->ptr,
			data->win_ptr, data->sprites.exit, data->x * 60, data->y * 60);
	else if (map->map_cpy[data->y][data->x] == 'C')
		mlx_put_image_to_window(data->ptr,
			data->win_ptr, data->sprites.coin, data->x * 60, data->y * 60);
}

void	display_sprites_in_screen(t_data_mlx *data, t_map_info *map)
{
	data->y = 0;
	while (map->map_cpy[data->y])
	{
		data->x = 0;
		while (map->map_cpy[data->y][data->x])
		{
			display_sprites_in_screen_y(data, map);
			data->x++;
		}
		data->y++;
	}
}

int	display_sprites(t_all_data *all_data)
{
	ft_print_map_cpy(all_data->map);
	display_sprites_in_screen(all_data->data, all_data->map);
	return (0);
}

int	display_game(t_data_mlx *data, t_map_info *map)
{
	t_all_data	all_data;

	data->nb_movement = 1;
	all_data.data = data;
	all_data.map = map;
	calcul_width_height(data, map);
	data->win_ptr = mlx_new_window(data->ptr,
			data->i, data->j, "SO_LONG");
	if (data->win_ptr == NULL)
		return (free(data->ptr), MLX_ERROR);
	mlx_hook(data->win_ptr, Expose, ExposureMask, display_sprites, &all_data);
	mlx_hook(data->win_ptr, KeyPress, KeyPressMask, &handle_keypress, &all_data);
	mlx_loop(data->ptr);
	return (0);
}
