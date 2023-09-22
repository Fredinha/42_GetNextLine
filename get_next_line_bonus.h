/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgomes-f <fgomes-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 14:59:02 by fgomes-f          #+#    #+#             */
/*   Updated: 2023/08/17 15:24:40 by fgomes-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# ifndef MAX_FILES
#  define MAX_FILES 500
# endif

char	*get_next_line(int fd);
char	*read_file(int fd, char *stash);
char	*ft_strchr(char *buffer, int target);
char	*ft_strjoin(char *stash, char const *buf);
char	*get_the_line(char *buffer);
char	*save_leftovers(char *buffer);
size_t	ft_strlen(const char *str);

#endif
