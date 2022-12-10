/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abchaban <abchaban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 16:23:33 by abchaban          #+#    #+#             */
/*   Updated: 2022/12/07 16:23:33 by abchaban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *s, ...)
{
	t_printf	data;
	va_list		parameters_infos;

	data.len = 0;
	data.nb_params = ft_search_params(s);
	va_start(parameters_infos, s);
	ft_convert(s, parameters_infos, &data);
	va_end(parameters_infos);
	return (data.len);
}
