/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trozain <trozain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 18:31:56 by trozain           #+#    #+#             */
/*   Updated: 2022/01/06 23:10:59 by trozain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t n)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (dst[i] && i < n)
		i++;
	j = i;
	while (src[i - j] && i + 1 < n)
	{
		dst[i] = src[i - j];
		i++;
	}
	if (i < n)
		dst[i] = '\0';
	return (j + ft_strlen(src));
}
