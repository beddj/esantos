/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esantos <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/24 22:25:07 by esantos           #+#    #+#             */
/*   Updated: 2016/09/28 00:27:45 by esantos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	size_t	big_len;
	size_t	little_len;
	size_t	count;
	char	*str1;

	big_len = ft_strlen((char*)big);
	little_len = ft_strlen((char*)little);
	str1 = (char*)big;
	if (big_len < little_len)
		return (NULL);
	if (!little_len)
		return (str1);
	count = big_len - little_len + 1;
	while (count)
	{
		if (!ft_memcmp(str1, (char*)little, little_len))
			return (str1);
		str1++;
		count--;
	}
	return (NULL);
}
