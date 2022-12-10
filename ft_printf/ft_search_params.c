/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_search_params.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abchaban <abchaban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 16:25:00 by abchaban          #+#    #+#             */
/*   Updated: 2022/12/07 16:25:00 by abchaban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_search_params(const char *str)
{
	int	count;
	int	i;
	int	j;

	j = 1;
	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == '%')
			j = 0;
		if (j == 0)
		{
			i++;
			if (ft_is_type(str[i]))
			{
				count++;
				j = 1;
			}
		}
		i++;
	}
	return (count);
}
