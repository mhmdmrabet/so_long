/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_nbr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abchaban <abchaban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 16:22:06 by abchaban          #+#    #+#             */
/*   Updated: 2022/12/07 16:22:06 by abchaban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_convert_nbr(const char *s, t_printf *data, va_list parameters_infos)
{
	if (*s == 'd' || *s == 'i')
		ft_putnbr(va_arg(parameters_infos, int), data);
	else if (*s == 'u')
		ft_putnbr_unsigned(va_arg(parameters_infos, unsigned int), data);
}
