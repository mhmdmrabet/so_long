/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abchaban <abchaban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 14:46:50 by abchaban          #+#    #+#             */
/*   Updated: 2022/12/07 14:46:50 by abchaban         ###   ########.fr       */
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
			ft_printf("%c", data->map[i][j]);
			j++;
		}
		ft_printf("\n");
		i++;
	}
	ft_printf("\n");
}

void	ft_print_map_cpy(t_map_info *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->len_map)
	{
		j = 0;
		while (j < data->len_line)
		{
			ft_printf("%c", data->map_cpy[i][j]);
			j++;
		}
		ft_printf("\n");
		i++;
	}
	ft_printf("\n");
}
