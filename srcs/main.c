/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abchaban <abchaban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 14:46:58 by abchaban          #+#    #+#             */
/*   Updated: 2022/12/07 14:46:58 by abchaban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./so_long.h"

int	launch_game(t_map_info *data, t_data_mlx *data_mlx)
{
	data_mlx->ptr = mlx_init();
	if (data_mlx->ptr == NULL)
		return (free_map(data->map, data->len_map),
			free_map(data->map_cpy, data->len_map), MLX_ERROR);
	display_game(data_mlx, data);
	return (free(data_mlx->ptr), free_map(data->map, data->len_map),
		free_map(data->map_cpy, data->len_map), 0);
	return (1);
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
			init_games(&data_mlx, p_data);
			if (ft_check_map(argv[1], p_data) == 0)
				return (free_map(data.map, data.len_map),
					free_map(data.map_cpy, data.len_map), 0);
			if (launch_game(p_data, &data_mlx) == 0)
				return (0);
		}
		else
			return (ft_printf("%s", msg), 0);
	}
	else
		return (ft_printf("%s", msg), 0);
}
