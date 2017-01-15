/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esantos <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/24 21:52:27 by esantos           #+#    #+#             */
/*   Updated: 2016/09/28 00:16:29 by esantos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		len;
	char	search;
	char	*str;

	search = (char)c;
	len = ft_strlen((char*)s) - 1;
	str = (char*)s;
	if (search == '\0')
		return (str + len + 1);
	while (len >= 0)
	{
		if (str[len] == search)
			return (str + len);
		len--;
	}
	return (0);
}
