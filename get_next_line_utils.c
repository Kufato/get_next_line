/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axcallet <axcallet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 18:07:13 by axcallet          #+#    #+#             */
/*   Updated: 2022/10/31 15:28:05 by axcallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_found_new_line(char *stash)
{
	int	i;

	i = 0;
	if (stash == NULL)
		return (0);
	while (stash[i] != '\0')
	{
		if (stash[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

void	ft_generate_line(char *stash, char **line)
{
	int	i;
	int	len_line;

	i = 0;
	while (stash[i] != '\0')
	{
		if (stash[i] == '\n')
		{
			len_line++;
			break ;
		}
		len_line++;
		i++;
	}
	*line = malloc(sizeof(char) * (len_line + 1));
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*final_str;

	i = 0;
	j = 0;
	final_str = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!final_str)
		return (NULL);
	ft_memcpy(final_str, s1, ft_strlen(s1));
	i = 0;
	j = ft_strlen(s1);
	while (s2[i] != '\0')
	{
		final_str[j] = s2[i];
		i++;
		j++;
	}
	final_str[j] = '\0';
	return (final_str);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char	*d;
	char	*s;
	size_t	i;

	i = 0;
	d = (char *)dest;
	s = (char *)src;
	if (d == NULL && s == NULL)
		return (NULL);
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (dest);
}

int	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (s == NULL)
		return (0);
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}
