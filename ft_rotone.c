/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotone.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esantos <esantos@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/10 16:11:02 by esantos           #+#    #+#             */
/*   Updated: 2016/10/10 16:53:31 by esantos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char ft_isalpha(char c);

void ft_rotone(char *str)
{
	int i;

	while(str[i] != '\0')
	{
		if( ft_isalpha(str[i]))
			str[i] = str[i] + 1;
		if(str[i] == 91 || str[i] == 123)
			str[i] = str[i] - 26;

		printf("%c", str[i]);
		i++;
	}
	printf("\n");

}

char ft_isalpha(char c)
{
	if((c >= 'a' && c <= 'z')  || (c >= 'A' && c <= 'Z'))
		return (1);
	else
		return (0);
}

int main(int argc, char **argv)
{
	ft_rotone(argv[1]);
	return (0);
}
