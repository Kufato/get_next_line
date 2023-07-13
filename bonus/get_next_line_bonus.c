/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axcallet <axcallet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 08:51:18 by axcallet          #+#    #+#             */
/*   Updated: 2022/11/14 17:13:31 by axcallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static char	*stash[1024];
	char		*line;

	if (fd < 0 || fd >= 1024 || BUFFER_SIZE <= 0)
		return (NULL);
	line = NULL;
	stash[fd] = ft_read_and_stash(fd, stash[fd]);
	if (!stash[fd] || stash[fd][0] == '\0')
	{
		free(stash[fd]);
		stash[fd] = NULL;
		return (NULL);
	}
	line = ft_extract_line(stash[fd], line);
	if (!line || line[0] == '\0')
	{
		free(stash[fd]);
		stash[fd] = NULL;
		free(line);
		return (NULL);
	}
	stash[fd] = ft_clean_stash(stash[fd]);
	return (line);
}

char	*ft_read_and_stash(int fd, char *stash)
{
	char	*buf;
	int		i;

	i = BUFFER_SIZE;
	while (ft_found_new_line(stash) == 0 && i == BUFFER_SIZE)
	{
		buf = ft_calloc(sizeof(char), BUFFER_SIZE + 1);
		i = read(fd, buf, BUFFER_SIZE);
		if (i == -1 || (stash == NULL && i == 0))
		{
			free(stash);
			free(buf);
			return (NULL);
		}
		stash = ft_strjoin(stash, buf);
		free(buf);
	}
	return (stash);
}

char	*ft_extract_line(char *stash, char *line)
{
	int	i;

	i = 0;
	line = ft_generate_line(stash, line);
	if (line == NULL)
		return (NULL);
	while (stash[i] != '\0')
	{
		if (stash[i] == '\n')
		{
			line[i] = stash[i];
			break ;
		}
		line[i] = stash[i];
		i++;
	}
	return (line);
}

char	*ft_clean_stash(char *stash)
{
	int		i;
	int		j;
	int		stash_len;
	char	*new_stash;

	i = 0;
	j = 0;
	while (stash[i] != '\0' && stash[i] != '\n')
		i++;
	stash_len = ft_strlen(stash);
	if (i != stash_len)
		new_stash = ft_calloc(sizeof(char), (stash_len - i) + 1);
	else
	{
		new_stash = NULL;
		free(stash);
		stash = NULL;
		return (NULL);
	}
	i++;
	while (stash[i] != '\0')
		new_stash[j++] = stash[i++];
	free(stash);
	stash = NULL;
	return (new_stash);
}
