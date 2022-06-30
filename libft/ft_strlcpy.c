/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trozain <trozain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 18:32:21 by trozain           #+#    #+#             */
/*   Updated: 2022/01/05 16:49:35 by trozain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *restdst, const char *restsrc, size_t n)
{
	unsigned int	i;

	i = 0;
	if (n > 0)
	{
		while (--n && restsrc[i])
		{
			restdst[i] = restsrc[i];
			i++;
		}
		restdst[i] = '\0';
	}
	while (restsrc[i])
		i++;
	return (i);
}
