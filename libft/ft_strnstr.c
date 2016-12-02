/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esantos <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/24 22:34:54 by esantos           #+#    #+#             */
/*   Updated: 2016/10/15 16:00:57 by esantos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	little_len;
	size_t	count;
	char	*str1;

	little_len = ft_strlen((char*)little);
	str1 = (char*)big;
	if (ft_strlen(str1) < little_len)
		return (NULL);
	if (little_len > len)
		return (NULL);
	count = len - little_len + 1;
	while (count)
	{
		if (!ft_memcmp(str1, (char*)little, little_len))
			return (str1);
		str1++;
		count--;
	}
	return (NULL);
}
