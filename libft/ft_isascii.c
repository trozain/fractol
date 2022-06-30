/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trozain <trozain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 14:28:54 by trozain           #+#    #+#             */
/*   Updated: 2021/12/23 15:47:57 by trozain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	else
		return (0);
}
/*
#include <stdio.h>
#include <ctype.h>

int main(int ac, char *av[])
{
	int result;

	char c;

	c = 127;
	result = isascii(c);
	printf("isascii 127 : %d\n", result);

	c = 0;
	result = isascii(c);
	printf("isascii 0 : %d\n", result);

	printf("my isascii : %d \n", ft_isascii(av[1]));
}
*/
