/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trozain <trozain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 15:01:34 by trozain           #+#    #+#             */
/*   Updated: 2022/07/21 20:16:22 by trozain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/fractol.h"

void	julia_init(t_data *data)
{
	data->width = 1000;
	data->height = 1000;
	data->color = 0x660000;
	data->zoom = 1;
	data->cre = -0.7;
	data->cim = 0.27015;
	data->new_x = 0;
	data->new_y = 0;
	data->oldre = 0;
	data->oldim = 0;
	data->max_n = 200;
	julia(data);
}

void	julia(t_data *data)
{
	int	n;
	int	x;
	int	y;

	n = 0;
	x = 100;
	y = 100;
	mlx_string_put(data->mlx_ptr, data->win_ptr, 500, 40, 0xffffff, "Julia");
	while (y < data->height)
	{
		while (x < data->width)
		{
			data->new_x = 1.5 * (x - data->width / 2) / (0.3 * data->zoom
					* data->width);
			data->new_y = (y - data->height / 2) / (0.3 * data->zoom
					* data->height);
			n = julia_x(data);
			if (n < data->max_n)
				mlx_pixel_put(data->mlx_ptr, data->win_ptr, x, y,
					(data->color * n / 100));
			x++;
		}
		y++;
		x = 100;
	}
}

int	julia_x(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->max_n && data->new_x * data->new_x
		+ data->new_y * data->new_y < 4)
	{
		data->oldre = data->new_x;
		data->oldim = data->new_y;
		data->new_x = data->oldre * data->oldre - data->oldim
			* data->oldim + data->cre;
		data->new_y = 2 * data->oldre * data->oldim + data->cim;
		i++;
	}
	return (i);
}
