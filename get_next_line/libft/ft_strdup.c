/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esantos <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/21 10:43:57 by esantos           #+#    #+#             */
/*   Updated: 2016/09/27 23:38:42 by esantos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(char *src)
{
	char	*copy;
	int		length;
	int		i;

	i = 0;
	while (src[i] != '\0')
	{
		i++;
		length = i;
	}
	copy = (char *)malloc(length + 1);
	if (copy == NULL)
		return (NULL);
	i = 0;
	while (i < length)
	{
		copy[i] = src[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}
