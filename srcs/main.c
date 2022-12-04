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


int	main(int argc, char **argv)
{
	t_map_info	*p_data;
	t_map_info	data;
	void		*mlx;
	void		*mlx_win;
	char		*msg;

	msg = "Error\nYour program must take a '.ber' file as a parameter.\n";
	if (argc == 2)
	{
		if (check_format_file(argv[1]))
		{
			p_data = &data;
			if (ft_check_map(argv[1], p_data) == 0)
				return (0);
			mlx = mlx_init();
			mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
			mlx_loop(mlx);
			return (0);
		}
		return (ft_printf("%s", msg), 0);
	}
	else
		return (ft_printf("%s", msg), 0);
}
