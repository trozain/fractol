/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trozain <trozain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 13:39:18 by trozain           #+#    #+#             */
/*   Updated: 2022/01/06 20:50:08 by trozain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	unsigned int	s_len;
	char			*substr;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (s_len < start)
	{
		substr = (char *)ft_calloc(1, sizeof(char));
		if (substr == 0)
			return (NULL);
		return (substr);
	}
	if (len > (size_t)s_len)
		substr = (char *)ft_calloc((size_t)ft_strlen(s) + 1, sizeof(char));
	else
		substr = (char *)ft_calloc((len + 1), sizeof(char));
	if (substr == 0)
		return (NULL);
	i = ft_strlcpy(substr, (s + start), len + 1);
	return (substr);
}
