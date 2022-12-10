/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abchaban <abchaban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 14:50:43 by abchaban          #+#    #+#             */
/*   Updated: 2022/12/07 14:50:43 by abchaban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned const char	*char_str1;
	unsigned const char	*char_str2;
	size_t				i;

	char_str1 = (unsigned const char *)s1;
	char_str2 = (unsigned const char *)s2;
	i = 0;
	while (i < n)
	{
		if (char_str1[i] != char_str2[i])
			return (char_str1[i] - char_str2[i]);
		i++;
	}
	return (0);
}
