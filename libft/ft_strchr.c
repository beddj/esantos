/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esantos <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/24 21:35:53 by esantos           #+#    #+#             */
/*   Updated: 2016/09/27 23:29:52 by esantos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	i;
	char	*str;

	i = 0;
	str = (char*)s;
	if (s)
	{
		while (s[i] != '\0')
		{
			if (s[i] == c)
				return (str + i);
			i++;
		}
		if (c == 0)
			return (str + i);
	}
	return (NULL);
}
