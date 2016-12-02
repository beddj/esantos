/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esantos <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/23 22:35:09 by esantos           #+#    #+#             */
/*   Updated: 2016/09/29 20:02:13 by esantos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *s1, const char *s2)
{
	char *ptr1;
	char *ptr2;

	ptr1 = s1;
	ptr2 = (char*)s2;
	while (*ptr1)
		ptr1++;
	while (*ptr2)
	{
		*ptr1 = *ptr2;
		ptr2++;
		ptr1++;
	}
	*ptr1 = '\0';
	return (s1);
}
