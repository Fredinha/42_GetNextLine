/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgomes-f <fgomes-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 13:06:27 by fgomes-f          #+#    #+#             */
/*   Updated: 2023/08/17 16:31:58 by fgomes-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_file(int fd, char *stash)
{
	char	*buf;
	int		n_bytes_read;

	n_bytes_read = 1;
	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	while (!ft_strchr(stash, '\n') && n_bytes_read != 0)
	{
		n_bytes_read = read(fd, buf, BUFFER_SIZE);
		if (n_bytes_read == -1)
		{
			free (buf);
			free (stash);
			return (NULL);
		}
		buf[n_bytes_read] = '\0';
		if (!buf)
			return (NULL);
		stash = ft_strjoin(stash, buf);
	}
	free (buf);
	return (stash);
}

char	*get_the_line(char *stash)
{
	int		i;
	char	*line;

	i = 0;
	if (!stash[i])
		return (NULL);
	while (stash[i] && stash[i] != '\n')
		i++;
	if (stash[i] == '\0')
		line = malloc(sizeof(char) * (i + 1));
	else
		line = malloc(sizeof(char) * (i + 2));
	if (!line)
		return (NULL);
	i = 0;
	while (stash[i] && stash[i] != '\n')
	{
		line[i] = stash[i];
		i++;
	}
	if (stash[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char	*save_leftovers(char *stash)
{
	int		i;
	int		j;
	char	*new_line;

	i = 0;
	j = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	if (!stash[i])
	{
		free(stash);
		return (NULL);
	}
	new_line = malloc(sizeof(char) * (ft_strlen(stash) - i + 1));
	if (!new_line)
		return (NULL);
	i++;
	while (stash[i])
		new_line[j++] = stash[i++];
	new_line[j] = '\0';
	free (stash);
	return (new_line);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*stash;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	stash = read_file(fd, stash);
	if (!stash)
		return (NULL);
	line = get_the_line(stash);
	stash = save_leftovers(stash);
	return (line);
}

/*int	main(void)
{
	int		fd;
	char	*string;

	fd = open("test1.txt", O_RDONLY);
	string = get_next_line(fd);
	printf("this is the first line: %s\n", string);
	free(string);
	string = get_next_line(fd);
	printf("this is the second line: %s\n", string);
	free(string);
	string = get_next_line(fd);
	printf("this is the third line: %s\n", string);
	free(string);
	string = get_next_line(fd);
	printf("this is the fourth line: %s\n", string);
	free(string);
	string = get_next_line(fd);
	printf("this is the fifth line: %s\n", string);
	free(string);
	return (0);
}*/
