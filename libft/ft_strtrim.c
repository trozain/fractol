/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trozain <trozain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 15:53:03 by trozain           #+#    #+#             */
/*   Updated: 2022/01/06 16:53:43 by trozain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	m_set(char c, char const *set);

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	debut;
	size_t	fin;
	char	*p;

	if (!s1 || !set)
		return (ft_strdup(" "));
	debut = 0;
	fin = ft_strlen(s1);
	while (m_set(s1[debut], set) == 0)
		debut++;
	if (debut == ft_strlen(s1))
	{
		p = ft_substr(s1, debut, fin - debut);
		return (p);
	}
	while (m_set(s1[fin - 1], set) == 0)
		fin--;
	p = ft_substr(s1, debut, fin - debut);
	return (p);
}

static int	m_set(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (0);
		i++;
	}
	return (1);
}
