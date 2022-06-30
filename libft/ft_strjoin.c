/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trozain <trozain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 16:03:30 by trozain           #+#    #+#             */
/*   Updated: 2022/01/07 16:28:40 by trozain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*newstrg(size_t size);

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*p;
	int		i;

	i = 0;
	if (!s1 || !s2)
		return (NULL);
	else
	{
		p = newstrg(ft_strlen(s1) + ft_strlen(s2) + 1);
		if (p)
		{
			while (*s1)
			{
				p[i++] = *s1;
				s1++;
			}
			while (*s2)
			{
				p[i++] = *s2;
				s2++;
			}
			return (p += '\0');
		}
	}
	return (NULL);
}

static char	*newstrg(size_t size)
{
	char	*strg;

	if (size == 0)
	{
		strg = malloc(sizeof(*strg) * (1));
		if (strg)
		{
			ft_memset(strg, '\0', (1));
			return (strg);
		}
	}
	else if (size)
	{
		strg = malloc(sizeof(*strg) * (size + 1));
		if (strg)
		{
			ft_memset(strg, '\0', (size + 1));
			return (strg);
		}
	}
	return (NULL);
}
