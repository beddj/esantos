/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esantos <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 16:00:01 by esantos           #+#    #+#             */
/*   Updated: 2016/12/10 17:14:13 by esantos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "./get_next_line.h"

int		get_next_line(const int fd, char **line)
{
	int				gotten;
	static char		*pointer;
	static char		*news = NULL;

	if ((!news && (news = ft_memalloc(sizeof(char))) == NULL) || line == NULL)
		return (-1);
	pointer = ft_strchr(news, '\n');
	while (pointer == NULL)
	{
		if ((gotten = ft_io(fd, &news)) == 0)
		{
			if ((pointer = ft_strchr(news, '\0')) == news)
				return (0);
		}
		else if (gotten < 0)
			return (-1);
		else
			pointer = ft_strchr(news, '\n');
	}
	*line = ft_strsub(news, 0, (pointer - news));
	pointer = ft_strdup(pointer + 1);
	free(news);
	news = pointer;
	return (1);
}

int		ft_io(int const fd, char **news)
{
	static int		gotten;
	static char		buffer[BUFF_SIZE + 1];
	static char		*arr;

	ft_memset(buffer, '\0', (BUFF_SIZE + 1));
	gotten = read(fd, buffer, BUFF_SIZE);
	if (gotten > 0)
	{
		buffer[gotten] = '\0';
		arr = ft_strjoin(*news, buffer);
		if (!arr)
			return (-1);
		free(*news);
		*news = arr;
	}
	return (gotten);
}
