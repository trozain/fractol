/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trozain <trozain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 17:50:38 by trozain           #+#    #+#             */
/*   Updated: 2021/12/23 17:59:38 by trozain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char		*d;
	const char	*s;
	char		*ss;
	char		*dd;

	d = dest;
	s = src;
	if (dest == 0 && src == 0)
		return (NULL);
	if (d < s)
		while (n--)
			*d++ = *s++;
	else
	{
		ss = (char *)s + (n - 1);
		dd = d + (n - 1);
		while (n--)
			*dd-- = *ss--;
	}
	return (dest);
}
