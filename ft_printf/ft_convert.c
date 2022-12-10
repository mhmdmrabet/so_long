/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abchaban <abchaban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 16:23:20 by abchaban          #+#    #+#             */
/*   Updated: 2022/12/07 16:23:20 by abchaban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_convert_all_hexa(const char *s, va_list ap, t_printf *data)
{
	if (*s == 'X')
		ft_convert_hexa(va_arg(ap, int), "0123456789ABCDEF", data);
	else if (*s == 'x')
		ft_convert_hexa(va_arg(ap, int), "0123456789abcdef", data);
}

void	ft_convert(const char *s, va_list ap, t_printf *data)
{
	data->nb_params = ft_search_params(s);
	while (*s)
	{
		if (*s != '%')
			ft_putchar_len(*s, data);
		if (*s == '%')
		{
			if (ft_is_type(*(s + 1)))
			{
				s++;
				if (*s == 'c' || *s == 's' || *s == '%')
					ft_convert_str(s, data, ap);
				else if (*s == 'd' || *s == 'i' || *s == 'u')
					ft_convert_nbr(s, data, ap);
				else if (*s == 'p')
					ft_convert_ptr(data, ap);
				else if (*s == 'X' || *s == 'x')
					ft_convert_all_hexa(s, ap, data);
			}
			else
				ft_putchar_len(*s, data);
		}
		s++;
		data->nb_params--;
	}
}
