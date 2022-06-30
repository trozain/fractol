/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trozain <trozain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 18:37:55 by trozain           #+#    #+#             */
/*   Updated: 2021/12/23 17:58:11 by trozain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *restsrc, size_t n)
{
	char		*d;
	const char	*s;

	if (restsrc == 0 && dst == 0)
		return (NULL);
	d = dst;
	s = restsrc;
	while (n--)
		*d++ = *s++;
	return (dst);
}
