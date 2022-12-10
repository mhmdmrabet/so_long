/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_type.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abchaban <abchaban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 16:23:26 by abchaban          #+#    #+#             */
/*   Updated: 2022/12/07 16:23:26 by abchaban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_is_type(char c)
{
	const char	*type = "cspdiuxX%";
	int			i;

	i = 0;
	while (type[i])
	{
		if (type[i] == c)
			return (1);
		i++;
	}
	return (0);
}
