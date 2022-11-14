/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axcallet <axcallet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 17:26:35 by axcallet          #+#    #+#             */
/*   Updated: 2022/11/14 09:34:13 by axcallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

int		ft_strlen(const char *s);
int		ft_check_buffer(char *buffer);
int		ft_found_new_line(char *stash);

char	*get_next_line(int fd);
char	*ft_clean_stash(char *stash);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_read_and_stash(int fd, char *stash);
char	*ft_add_to_stash(char *stash, char *buf);
char	*ft_extract_line(char *stash, char *line);
char	*ft_generate_line(char *stash, char *line);

void	*ft_calloc(size_t nmemb, size_t size);

#endif
