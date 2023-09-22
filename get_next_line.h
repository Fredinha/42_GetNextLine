/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgomes-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 12:43:09 by fgomes-f          #+#    #+#             */
/*   Updated: 2023/08/17 14:53:15 by fgomes-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char	*get_next_line(int fd);
char	*read_file(int fd, char *stash);
char	*ft_strchr(char *buffer, int target);
char	*ft_strjoin(char *stash, char const *buf);
char	*get_the_line(char *buffer);
char	*save_leftovers(char *buffer);
size_t	ft_strlen(const char *str);

#endif
