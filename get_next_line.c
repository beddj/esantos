/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esantos <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 16:00:01 by esantos           #+#    #+#             */
/*   Updated: 2016/11/23 12:11:35 by esantos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "get_next_line.h"

int		get_next_line(const int fd, char **line)
{
	int				gotten;
	static char		buffer[BUFF_SIZE];
	static char		*pointer;
	static char		*news;

	if ((news = (char*)ft_memalloc(sizeof(char))) == NULL)
		return (0);
	pointer = ft_strchr(buffer, '\n');
	if ((gotten = ft_io(fd, &news)) == 0)
	{
		pointer = ft_strchr(news, '\0');
		if (pointer == *line)
			return (0);
	}
	else if (gotten < 0)
		return (-1);
	else
		pointer = ft_strchr(news, '\n');
	*line = ft_strsub(news, 0, pointer - news);
	if (line == NULL)
		return (0);
	pointer = ft_strdup(pointer + 1);
	free(news);
	news = pointer;
	return (1);
}

int		ft_io(int fd, char **news)
{
	static int		gotten;
	static char		buffer[BUFF_SIZE];
	static char		*arr;

	while ((gotten = read(fd, buffer, BUFF_SIZE)) != 0)
	{
		buffer[gotten] = '\0';
		arr = ft_strjoin(*news, buffer);
		*news = arr;
	}
	return (gotten);
}
