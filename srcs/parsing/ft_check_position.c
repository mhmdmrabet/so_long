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

int	isnt_obstacle(t_map_info *data, char search, int i, int j)
{
	if (data->map[i][j] != '1' && data->map[i][j] != 'P')
	{
		if (data->map[i][j] != 'E' && (data->map[i][j] == '0'))
			if (data->map[i][j] != '*')
				return (1);
	}
	return (0);
}

int	check_e_around_elmnt(t_map_info *data, int i, int j)
{
	if (data->map[i][j - 1] == 'E')
		return (1);
	if (data->map[i][j + 1] == 'E')
		return (1);
	if (data->map[i - 1][j] == 'E')
		return (1);
	if (data->map[i + 1][j] == 'E')
		return (1);
	return (0);
}


// void	check_and_replace(t_map_info *data, int i, int j, int *add_x)
// {
// 	if (isnt_obstacle(data, '*', i, j - 1))
// 	{
// 		data->map[i][j - 1] = '*';
// 		*add_x = 1;
// 	}
// }

int	insert_in_line(t_map_info *data, int i, int j, int *add_x)
{
	while (j < data->len_line)
	{
		if (data->map[i][j] == '*')
		{
			if (check_e_around_elmnt(data, i, j))
				return (1);
			if (isnt_obstacle(data, '*', i, j - 1))
			{
				data->map[i][j - 1] = '*';
				*add_x = 1;
			}
			if (isnt_obstacle(data, '*', i, j + 1))
			{
				data->map[i][j + 1] = '*';
				*add_x = 1;
			}
			if (isnt_obstacle(data, '*', i + 1, j))
			{
				data->map[i + 1][j] = '*';
				*add_x = 1;
			}
			if (isnt_obstacle(data, '*', i - 1, j))
			{
				data->map[i - 1][j] = '*';
				*add_x = 1;
			}
		}
		j++;
	}
	return (0);
}

int	insert_around_x(t_map_info *data, int *add_x)
{
	int	result;
	int	i;
	int	j;

	result = 0;
	i = 0;
	*add_x = 0;
	while (i < data->len_map)
	{
		j = 0;
		// result = insert_in_line(data, i, j, add_x);
		while (j < data->len_line)
		{
			if (data->map[i][j] == '*')
			{
				if (check_e_around_elmnt(data, i, j))
					return (1);
				if (isnt_obstacle(data, '*', i, j - 1))
				{
					data->map[i][j - 1] = '*';
					*add_x = 1;
				}
				if (isnt_obstacle(data, '*', i, j + 1))
				{
					data->map[i][j + 1] = '*';
					*add_x = 1;
				}
				if (isnt_obstacle(data, '*', i + 1, j))
				{
					data->map[i + 1][j] = '*';
					*add_x = 1;
				}
				if (isnt_obstacle(data, '*', i - 1, j))
				{
					data->map[i - 1][j] = '*';
					*add_x = 1;
				}
			}
			j++;
		}
		i++;
	}
	return (result);
}

int	fill_around_depart(t_map_info *data)
{
	int		i;
	int		j;
	int		add_x;
	char	replacement;

	replacement = '*';
	add_x = 1;
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
	return (1);
}

int	fill_around(t_map_info *data)
{
	int		add_x;

	add_x = 1;
	fill_around_depart(data);
	ft_print_map(data);
	while (insert_around_x(data, &add_x) == 0 && add_x == 1)
		ft_print_map(data);
	ft_print_map(data);
	return (1);
}
