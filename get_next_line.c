/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axcallet <axcallet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 17:25:46 by axcallet          #+#    #+#             */
/*   Updated: 2022/10/31 15:28:04 by axcallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*stash = NULL;
	char		*line;
	int			index;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	index = 1;
	line = NULL;
	stash = ft_read_and_stash(fd, stash, &index);
	if (stash == NULL)
		return (NULL);
	line = ft_extract_line(stash, line);
	stash = ft_clean_stash(stash);
	if (!line)
		free(stash);
	return (line);
}

char	*ft_read_and_stash(int fd, char *stash, int *index_ptr)
{
	char	*buf;

	if (stash == NULL)
		stash = malloc(sizeof(char) * 1);
	while (ft_found_new_line(stash) == 0 && *index_ptr != 0)
	{
		buf = malloc(sizeof(char) * BUFFER_SIZE + 1);
		if (!buf)
			return (NULL);
		*index_ptr = (int)read(fd, buf, BUFFER_SIZE);
		if ((stash == NULL && *index_ptr == 0) || *index_ptr == -1)
		{
			free(buf);
			return (NULL);
		}
		buf[*index_ptr] = '\0';
		stash = ft_add_to_stash(stash, buf);
		free(buf);
	}
	return (stash);
}

char	*ft_add_to_stash(char *stash, char *buf)
{
	char	*str;

	if (stash == NULL || buf == NULL)
		return (NULL);
	str = ft_strjoin(stash, buf);
	return (str);
}

char	*ft_extract_line(char *stash, char *line)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (stash == NULL)
		return (NULL);
	ft_generate_line(stash, &line);
	if (line == NULL)
		return (NULL);
	if (stash[i] == '\n')
	{
		line[0] = '\n';
		line[1] = '\0';
		return (line);
	}
	while (stash[i] != '\n')
	{
		line[j] = stash[i];
		i++;
		j++;
	}
	line[j] = '\0';
	return (line);
}

char	*ft_clean_stash(char *stash)
{
	int		i;
	int		j;
	char	*new_stash;

	i = 0;
	j = 0;
	if (stash == NULL)
		return (NULL);
	while (stash[i] != '\0' && stash[i] != '\n')
		i++;
	i++;
	new_stash = malloc(sizeof(char) * ft_strlen(&stash[i]) + 1);
	if (new_stash == NULL)
		return (NULL);
	while (stash[i] != '\0')
	{
		new_stash[j] = stash[i];
		i++;
		j++;
	}
	new_stash[j] = '\0';
	free(stash);
	return (new_stash);
}
