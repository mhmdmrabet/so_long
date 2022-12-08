/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abchaban <abchaban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 14:53:14 by abchaban          #+#    #+#             */
/*   Updated: 2022/12/07 14:53:14 by abchaban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*substr;
	size_t	s_len;
	size_t	malloc_len;

	s_len = ft_strlen(s);
	i = 0;
	malloc_len = len;
	if (len > (s_len - start))
		malloc_len = s_len - start;
	if (start > s_len)
		malloc_len = 0;
	substr = (char *)malloc(sizeof(char) * (malloc_len + 1));
	if (!substr)
		return (NULL);
	while (i < malloc_len && s[start])
	{
		substr[i] = s[start];
		i++;
		start++;
	}
	substr[i] = '\0';
	return (substr);
}
