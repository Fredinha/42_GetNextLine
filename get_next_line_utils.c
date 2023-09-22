/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgomes-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 12:52:59 by fgomes-f          #+#    #+#             */
/*   Updated: 2023/08/17 14:45:02 by fgomes-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(char *stash, int target)
{
	int	i;

	i = 0;
	if (!stash)
		return (NULL);
	while (stash[i])
	{
		if ((unsigned char)stash[i] == (unsigned char)target)
			return (&stash[i]);
		i++;
	}
	return (NULL);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *stash, char const *buf)
{
	int		i;
	int		j;
	char	*join;

	j = 0;
	if (!stash)
	{
		stash = malloc(sizeof(char) * 1);
		stash[0] = '\0';
	}
	i = ft_strlen(stash);
	join = malloc(sizeof(char) * (i + ft_strlen(buf) + 1));
	if (join == NULL)
		return (NULL);
	while (stash[j])
	{
		join[j] = stash[j];
		j++;
	}
	j = -1;
	while (buf[++j])
		join[i + j] = buf[j];
	join[i + j] = '\0';
	free (stash);
	return (join);
}
