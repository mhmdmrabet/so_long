/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_display_map.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abchaban <abchaban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 14:45:02 by abchaban          #+#    #+#             */
/*   Updated: 2022/12/08 11:35:47 by abchaban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../so_long.h"

void	free_map(char **map, int size)
{
	int			i;

	i = 0;
	while (i < size)
	{
		free(map[i]);
		i++;
	}
	free(map);
}

void	free_sprites(t_all_data *data)
{
	mlx_destroy_image(data->data->ptr, data->data->sprites.coin);
	mlx_destroy_image(data->data->ptr, data->data->sprites.floor);
	mlx_destroy_image(data->data->ptr, data->data->sprites.perso);
	mlx_destroy_image(data->data->ptr, data->data->sprites.exit);
	mlx_destroy_image(data->data->ptr, data->data->sprites.wall);
}

int	destroy_free_win(t_all_data *data)
{
	free_sprites(data);
	mlx_destroy_window(data->data->ptr, data->data->win_ptr);
	mlx_destroy_display(data->data->ptr);
	free(data->data->ptr);
	free_map(data->map->map_cpy, data->map->len_map);
	free_map(data->map->map, data->map->len_map);
	exit(EXIT_SUCCESS);
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
