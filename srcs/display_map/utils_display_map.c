/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_display_map.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abchaban <abchaban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 16:00:22 by abchaban          #+#    #+#             */
/*   Updated: 2022/12/06 17:06:43 by abchaban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../so_long.h"

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

void	destroy_free_win(t_all_data *data)
{
	mlx_destroy_window(data->data->ptr, data->data->win_ptr);
	data->data->win_ptr = NULL;
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
