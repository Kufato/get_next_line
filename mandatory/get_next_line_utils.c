/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axcallet <axcallet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 18:07:13 by axcallet          #+#    #+#             */
/*   Updated: 2022/11/08 16:33:28 by axcallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_found_new_line(char *stash)
{
	int	i;

	i = 0;
	if (!stash)
		return (0);
	while (stash[i] != '\0')
	{
		if (stash[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*ft_generate_line(char *stash, char *line)
{
	int	i;

	i = 0;
	if (stash == NULL)
		return (NULL);
	while (stash[i] != '\0')
	{
		if (stash[i] == '\n')
		{
			i++;
			break ;
		}
		i++;
	}
	line = ft_calloc(sizeof(char), i + 1);
	return (line);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*final_str;

	i = 0;
	j = 0;
	if (s2 == NULL)
		return (NULL);
	final_str = ft_calloc(sizeof(char), (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!final_str)
		return (NULL);
	while (s1 && s1[i] != '\0')
		final_str[j++] = s1[i++];
	i = 0;
	while (s2[i] != '\0')
		final_str[j++] = s2[i++];
	free(s1);
	return (final_str);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*str;
	size_t	nb;
	size_t	i;

	if (nmemb >= 65535 && size >= 65535)
		return (NULL);
	nb = nmemb * size;
	str = malloc(sizeof(char) * nb);
	if (!str)
		return (NULL);
	i = 0;
	while (i < nb)
	{
		str[i] = '\0';
		i++;
	}
	return ((void *)str);
}

int	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (s == NULL)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}
