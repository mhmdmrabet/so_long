/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abchaban <abchaban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 14:52:54 by abchaban          #+#    #+#             */
/*   Updated: 2022/12/07 14:52:54 by abchaban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	len_little;
	char	*big_bis;
	char	*little_bis;

	big_bis = (char *)big;
	little_bis = (char *)little;
	len_little = ft_strlen(little);
	if (*little_bis == 0)
		return (big_bis);
	i = 0;
	while (big_bis[i])
	{
		j = 0;
		while (big_bis[i + j] == little_bis[j] && (i + j) < len)
		{
			j++;
			if (j == len_little)
				return (&big_bis[i]);
		}
		i++;
	}
	return (0);
}
