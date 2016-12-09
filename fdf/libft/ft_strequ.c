/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esantos <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/25 20:21:49 by esantos           #+#    #+#             */
/*   Updated: 2016/09/29 20:50:52 by esantos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strequ(char const *s1, char const *s2)
{
	char *str1;
	char *str2;

	str1 = (char*)s1;
	str2 = (char*)s2;
	if (!s1 || !s2)
		return (0);
	if (ft_strcmp(str1, str2) == 0)
		return (1);
	return (0);
}
