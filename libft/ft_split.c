/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trozain <trozain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 16:02:25 by trozain           #+#    #+#             */
/*   Updated: 2022/01/07 15:40:59 by trozain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*word(const char *str, int start, int finish);
static int	count(const char *str, char c);

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	j;
	int		k;
	char	**split;

	if (!s)
		return (NULL);
	split = malloc((count(s, c) + 1) * sizeof(char *));
	if (!split)
		return (0);
	i = -1;
	j = 0;
	k = -1;
	while (++i <= ft_strlen(s))
	{
		if (s[i] != c && k < 0)
			k = i;
		else if ((s[i] == c || i == ft_strlen(s)) && k >= 0)
		{
			split[j++] = word(s, k, i);
			k = -1;
		}
	}
	split[j] = 0;
	return (split);
}

static int	count(const char *str, char c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (*str)
	{
		if (*str != c && j == 0)
		{
			j = 1;
			i++;
		}
		else if (*str == c)
			j = 0;
		str++;
	}
	return (i);
}

static char	*word(const char *str, int start, int finish)
{
	char	*w;
	int		i;

	i = 0;
	w = malloc((finish - start + 1) * sizeof(char));
	while (start < finish)
		w[i++] = str[start++];
	w[i] = '\0';
	return (w);
}
