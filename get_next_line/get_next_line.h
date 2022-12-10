/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abchaban <abchaban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 14:55:13 by abchaban          #+#    #+#             */
/*   Updated: 2022/12/07 14:55:13 by abchaban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 2
# endif

size_t	ft_strlen(const char *s);
char	*ft_get_stash_from_read(int fd, char *stash);
void	*ft_calloc(size_t nmemb, size_t size);
void	ft_clean_tmp_and_save_stash(char *tmp, char *stash);
char	*ft_strdup(const char *s);
char	*ft_join_and_free_tmp(char *buffer, char *buffer_from_read);
char	*ft_extract_line_from_stash(char *stash);
char	*ft_strjoin(char const *buffer, char const *buffer_from_read);
char	*ft_strchr(const char *s, int c);
char	*get_next_line(int fd);

#endif
