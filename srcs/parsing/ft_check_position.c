/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_positionXc                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmrabet <mmrabet@studentX42Xfr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 17:08:36 by mmrabet           #+#    #+#             */
/*   Updated: 2022/11/30 17:08:36 by mmrabet          ###   ########Xfr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../so_long.h"

void	ft_print_map(t_map_info *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->len_map)
	{
		j = 0;
		while (j < data->len_line)
		{
			printf("%c", data->map[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
}

void	insert_around_depart(t_map_info *data, int replacement)
{
	int	i;
	int	j;

	i = data->map_p_index;
	j = data->line_p_index;
	if (data->map[i + 1][j] != '1' && data->map[i + 1][j] != 'E')
		data->map[i + 1][j] = replacement;
	if (data->map[i - 1][j] != '1' && data->map[i - 1][j] != 'E')
		data->map[i - 1][j] = replacement;
	if (data->map[i][j + 1] != '1' && data->map[i][j + 1] != 'E')
		data->map[i][j + 1] = replacement;
	if (data->map[i][j - 1] != '1' && data->map[i][j - 1] != 'E')
		data->map[i][j - 1] = replacement;
	return ;
}

int	is_obstacle(t_map_info *data, char search, int i, int j)
{
	if (data->map[i][j] != '1' && data->map[i][j] != 'P')
	{
		if (data->map[i][j] != 'E' && (data->map[i][j] > search
			|| data->map[i][j] == '0'))
			return (1);	
	}
	return (0);
}

int	insert_around(t_map_info *data, char search, int replacement)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->len_map)
	{
		j = 0;
		while (j < data->len_line)
		{
			if (data->map[i][j] == search)
			{
				if (is_obstacle(data, search, i, j - 1))
					data->map[i][j - 1] = replacement;
				if (is_obstacle(data, search, i, j + 1))
					data->map[i][j + 1] = replacement;
				if (is_obstacle(data, search, i + 1, j))
					data->map[i + 1][j] = replacement;
				if (is_obstacle(data, search, i - 1, j))
					data->map[i - 1][j] = replacement;
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	ft_find_path(t_map_info *data)
{
	int	i;
	int result;

	i = '2';
	result = 0;
	insert_around_depart(data, i);
	while (result < 4)
	{
		insert_around(data, i, ++i);
		result++;
	}
}
