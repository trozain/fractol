/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trozain <trozain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 14:31:55 by trozain           #+#    #+#             */
/*   Updated: 2022/01/05 15:21:19 by trozain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int	i;

	i = 0;
	if (n == 0)
		return (0);
	while (s1[i] == s2[i] && i < (n - 1) && s1[i] && s2[i])
	{
		++i;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

/*
int	main(int argc, char *argv[])
{
	printf("fonction: %d\n", ft_strncmp(argv[1], argv[2], atoi(argv[3])));
	printf("strncmp: %d\n", strncmp(argv[4], argv[5], atoi(argv[6])));
	(void)	argc;
}*/
