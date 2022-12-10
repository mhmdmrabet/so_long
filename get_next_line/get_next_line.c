/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abchaban <abchaban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 14:55:03 by abchaban          #+#    #+#             */
/*   Updated: 2022/12/07 14:55:03 by abchaban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_get_stash_from_read(int fd, char *tmp)
{
	char	*buffer;
	int		result;

	if (!tmp)
		tmp = ft_calloc(1, 1);
	if (!tmp)
		return (NULL);
	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (free(tmp), NULL);
	buffer[0] = '\0';
	result = 1;
	while (result > 0 && (ft_strchr(buffer, '\n') == 0))
	{
		result = read(fd, buffer, BUFFER_SIZE);
		if (result == -1)
			return (free(buffer), free(tmp), NULL);
		buffer[result] = '\0';
		tmp = ft_join_and_free_tmp(tmp, buffer);
	}
	free(buffer);
	return (tmp);
}

char	*ft_extract_line_from_stash(char *tmp)
{
	char	*line;
	int		len_line;
	int		i;

	len_line = 0;
	i = 0;
	if (!tmp[i])
		return (NULL);
	while (tmp[len_line] && tmp[len_line] != '\n')
		len_line ++;
	line = ft_calloc(len_line + 2, sizeof(char));
	if (!line)
		return (NULL);
	while (tmp[i] && tmp[i] != '\n')
	{
		line[i] = tmp[i];
		i++;
	}
	return (line);
}

void	ft_clean_tmp_and_save_stash(char *tmp, char *stash)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (tmp[i] && tmp[i] != '\n')
		i++;
	if (!tmp[i])
	{
		stash[0] = '\0';
		return ;
	}
	i++;
	while (tmp[i])
		stash[j++] = tmp[i++];
	stash[j] = '\0';
}

char	*ft_join_and_free_tmp(char *tmp_stash, char *buffer)
{
	char	*tmp;

	tmp = ft_strjoin(tmp_stash, buffer);
	free(tmp_stash);
	return (tmp);
}

char	*get_next_line(int fd)
{
	static char	stash[((BUFFER_SIZE > 0) * BUFFER_SIZE) + 1];
	char		*line;
	char		*tmp;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	tmp = ft_strdup(stash);
	tmp = ft_get_stash_from_read(fd, tmp);
	if (!tmp)
		return (NULL);
	line = ft_extract_line_from_stash(tmp);
	ft_clean_tmp_and_save_stash(tmp, stash);
	free(tmp);
	return (line);
}

// int	main(void)
// {
// 	char		*line;
// 	const int	fd = open("explication.txt", O_RDONLY);
// 	int			i;

// 	i = 0;
// 	while (i < 2)
// 	{
// 		line = get_next_line(fd);
// 		printf("LINE %d : %s\n", i, line);
// 		free(line);
// 		i++;
// 	}
// 	close(fd);
// 	return (0);
// }
