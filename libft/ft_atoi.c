/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trozain <trozain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 14:29:16 by trozain           #+#    #+#             */
/*   Updated: 2022/01/06 23:35:49 by trozain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str);

int	ft_atoi(const char *str)
{	
	int			a;
	long int	n;
	int			i;

	a = 1;
	n = 0;
	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || (str[i] == 32))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			a *= -1;
		i++;
	}
	while (str[i] > 47 && str[i] < 58)
	{
		n = (n * 10) + (str[i] - '0');
		i++;
	}
	return (n * a);
}
