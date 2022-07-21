/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trozain <trozain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 15:02:07 by trozain           #+#    #+#             */
/*   Updated: 2022/07/21 19:26:12 by trozain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/* x = reel / y = imaginary */

void	mandelbrot_init(t_data *data)
{
	data->width = 1000;
	data->height = 1000;
	data->min_x = -2.05;
	data->max_x = 1.2;
	data->min_y = -1.3;
	data->max_y = 1.2;
	data->color = 0x660000;
	data->zoom = 200;
	data->max_n = 100;
	mandelbrot(data);
}

int	find_n(double cr, double ci, double max_n)
{
	int			i;
	double		zr;
	double		zi;
	double		temp;

	i = 0;
	zr = 0;
	zi = 0;
	while (i < max_n && zr * zr + zi * zi < 4.0)
	{
		temp = zr * zr - zi * zi + cr;
		zi = 2.0 * zr * zi + ci;
		zr = temp;
		i++;
	}
	return (i);
}

void	mandelbrot(t_data *data)
{
	int		x;
	int		y;
	int		n;

	x = 1;
	y = 1;
	mlx_string_put(data->mlx_ptr, data->win_ptr, 500, 40, 0xffffff,
		"Mandelbrot Set");
	while (x < data->width)
	{
		while (y < data->height)
		{
			data->cre = find_real(x, data);
			data->cim = find_imaginary(y, data);
			n = find_n(data->cre, data->cim, data->max_n);
			if (n == data->max_n)
				mlx_pixel_put(data->mlx_ptr, data->win_ptr, x, y, 0x000000);
			else
				mlx_pixel_put(data->mlx_ptr, data->win_ptr, x, y,
					(data->color * n / 1));
			y++;
		}
		x++;
		y = 1;
	}
}

double	find_real(int x, t_data *data)
{
	double	range;

	range = data->max_x - data->min_x;
	return (x * (range / data->width) + data->min_x);
}

double	find_imaginary(int y, t_data *data)
{
	double	range;

	range = data->max_y - data->min_y;
	return (y * (range / data->height) + data->min_y);
}
