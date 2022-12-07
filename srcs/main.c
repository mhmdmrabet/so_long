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
				return (free_map(data.map, data.len_map), 0);
			data_mlx.ptr = mlx_init();
			if (data_mlx.ptr == NULL)
				return (MLX_ERROR);
			data_mlx.x = 0;
			data_mlx.y = 0;
			display_game(&data_mlx, p_data);
			return (free(data_mlx.ptr), free_map(data.map, data.len_map),
				free_map(data.map_cpy, data.len_map), 0);
		}
		else
			return (ft_printf("%s", msg), 0);
	}
	else
		return (ft_printf("%s", msg), 0);
}
