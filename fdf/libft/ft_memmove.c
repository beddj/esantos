/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esantos <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/22 19:30:54 by esantos           #+#    #+#             */
/*   Updated: 2016/09/27 23:16:42 by esantos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_move(unsigned char *dst, unsigned char *sr, size_t len)
{
	size_t i;

	i = 0;
	if (sr > dst)
	{
		while (i < len)
		{
			dst[i] = sr[i];
			i++;
		}
	}
	else
	{
		i = len - 1;
		while (i > 0)
		{
			dst[i] = sr[i];
			i--;
		}
		dst[i] = sr[i];
	}
}

void			*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t			i;
	unsigned char	*dest;
	unsigned char	*sr;

	i = 0;
	dest = (unsigned char *)dst;
	sr = (unsigned char *)src;
	if (sr != dest && len > 0)
		ft_move(dest, sr, len);
	return ((void *)dst);
}
