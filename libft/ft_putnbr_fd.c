/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fr_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trozain <trozain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 18:56:29 by trozain           #+#    #+#             */
/*   Updated: 2022/01/05 19:26:03 by trozain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	nb;

	nb = n;
	if (n < 0)
	{
		ft_putchar_fd(('-'), fd);
		nb = -nb;
	}
	else
		nb = n;
	if (nb > 9)
	{
		ft_putnbr_fd(nb / 10, fd);
		nb = nb % 10;
	}
	ft_putchar_fd(nb + '0', fd);
}
