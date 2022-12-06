/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmrabet <mmrabet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 18:42:28 by mmrabet           #+#    #+#             */
/*   Updated: 2022/11/28 18:42:28 by mmrabet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./so_long.h"

int	check_format_file(char *pathname)
{
	size_t	strlen;

	strlen = ft_strlen(pathname) - 1;
	if (pathname[strlen--] == 'r')
		if (pathname[strlen--] == 'e')
			if (pathname[strlen--] == 'b')
				if (pathname[strlen--] == '.')
					return (1);
	return (0);
}

void	free_map(char **map)
{
	int			i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

void	destroy_free_win(t_data_mlx *data)
{
	mlx_destroy_window(data->ptr, data->win_ptr);
	data->win_ptr = NULL;
}

int	handle_keypress(int keysym, t_data_mlx *data)
{
	if (keysym == XK_Escape)
		destroy_free_win(data);
	return (0);
}

void	create_sprites(t_data_mlx *data)
{
	int	img_width;
	int	img_height;

	data->sprites->wall = mlx_xpm_file_to_image(data->ptr,
			"wall.xpm", &img_width, &img_height);
}

void	display_sprites_in_screen_y(t_data_mlx *data, t_map_info *map)
{
	void	*img;
	void	*img2;
	int		img_width;
	int		img_height;

	img = mlx_xpm_file_to_image(data->ptr,
			"wall.xpm", &img_width, &img_height);
	img2 = mlx_xpm_file_to_image(data->ptr,
			"floor.xpm", &img_width, &img_height);
	printf("LA-------------------------------------\n");
	ft_print_map(map);
	// if (map->map[data->x][data->y] == '1')
		mlx_put_image_to_window(data->ptr,
			data->win_ptr, img, data->x * 60, data->y * 60);
	// else
	// 	mlx_put_image_to_window(data->ptr,
	// 		data->win_ptr, img2, data->x * 60, data->y * 60);
}

void	display_sprites_in_screen(t_data_mlx *data, t_map_info *map)
{
	data->x = 0;
	while (data->x < 6)
	{
		data->y = 0;
		while (data->y < 6)
		{
			display_sprites_in_screen_y(data, map);
			data->y++;
		}
		data->x++;
	}
}

int	display_sprites(t_data_mlx *data, t_map_info *map)
{

	// create_sprites(data);
	display_sprites_in_screen(data, map);
	return (0);
}

void	calcul_width_height(t_data_mlx *data, t_map_info *map)
{
	data->width = map->len_line;
	data->height = map->len_map;
	data->i = data->width * 60;
	if (data->i > 2046)
		data->i = 2046;
	data->j = data->height * 60;
	if (data->j > 1040)
		data->j = 1040;
}

int	display_game(t_data_mlx *data, t_map_info *map)
{
	int	i;

	i = 0;
	ft_fill_map("Map.ber", map);
	calcul_width_height(data, map);
	data->win_ptr = mlx_new_window(data->ptr,
			data->i, data->j, "SO_LONG");
	if (data->win_ptr == NULL)
		return (free(data->ptr), MLX_ERROR);
	mlx_hook(data->win_ptr, Expose, ExposureMask, display_sprites, data);
	mlx_hook(data->win_ptr, KeyPress, KeyPressMask, &handle_keypress, data);
	mlx_loop(data->ptr);
	return (0);
}

int	main(int argc, char **argv)
{
	t_map_info		*p_data;
	t_map_info		data;
	t_data_mlx		data_mlx;
	char			*msg;

	msg = "Error\nYour program must take a '.ber' file as a parameter.\n";
	if (argc == 2)
	{
		if (check_format_file(argv[1]))
		{
			p_data = &data;
			if (ft_check_map(argv[1], p_data) == 0)
				return (free_map(data.map), 0);
			// data_mlx.ptr = mlx_init();
			// if (data_mlx.ptr == NULL)
			// 	return (MLX_ERROR);
			// ft_fill_map(argv[1], p_data);
			// display_game(&data_mlx, p_data);
			// ft_print_map(p_data);
			// return (free(data_mlx.ptr), free_map(data.map), 0);
		}
		else
			return (ft_printf("%s", msg), 0);
	}
	else
		return (ft_printf("%s", msg), 0);
}
