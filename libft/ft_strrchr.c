/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abchaban <abchaban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 14:53:01 by abchaban          #+#    #+#             */
/*   Updated: 2022/12/07 14:53:01 by abchaban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*result;

	result = NULL;
	i = 0;
	if (c == 0)
		return (ft_strlen(s) + (char *)s);
	while (s[i])
	{
		if (s[i] == (char)c)
			result = (char *)(&s[i]);
		i++;
	}
	return (result);
}
