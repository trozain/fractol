/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trozain <trozain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 18:33:30 by trozain           #+#    #+#             */
/*   Updated: 2022/01/06 22:37:53 by trozain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	c;
	size_t	n_len;

	i = 0;
	n_len = ft_strlen(needle);
	if (n_len == 0 || haystack == needle)
		return ((char *)haystack);
	while (haystack[i] && i < len)
	{
		c = 0;
		while (haystack[i + c] && needle[c]
			&& haystack[i + c] == needle[c] && i + c < len)
			c++;
		if (c == n_len)
			return ((char *)haystack + i);
		i++;
	}
	return (0);
}
