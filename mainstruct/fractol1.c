/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trozain <trozain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 15:01:45 by trozain           #+#    #+#             */
/*   Updated: 2022/07/21 20:16:24 by trozain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/fractol.h"
#include "../lib/keys.h"

void	ft_zoom(int x, int y, t_data *data)
{
	data->min_x = (x / data->zoom + data->min_x) - (x / (data->zoom * 1.2));
	data->min_y = (y / data->zoom + data->min_y) - (y / (data->zoom * 1.2));
	data->zoom *= 1.2;
	data->max_n++;
}

void	ft_dezoom(int x, int y, t_data *data)
{
	data->min_x = (x / data->zoom + data->min_x) - (x
			/ (data->zoom / 1.2));
	data->min_y = (y / data->zoom + data->min_y) - (y / (data->zoom / 1.2));
	data->zoom /= 1.2;
	data->max_n--;
}

int	mouse_hook(int mouse, int x, int y, t_data *data)
{
	if (data->fractol == 0)
	{
		if (mouse == SCROLL_DOWN || mouse == RIGHT_CLIC)
			ft_zoom(x, y, data);
		else if (mouse == SCROLL_UP || mouse == LEFT_CLIC)
			ft_dezoom(x, y, data);
		mlx_clear_window(data->mlx_ptr, data->win_ptr);
		mandelbrot(data);
	}
	else if (data->fractol == 1)
		julia_zoom(data, mouse);
	put_text(data);
	if (data->fractol == 2)
	{
		if (mouse == RIGHT_CLIC || mouse == SCROLL_DOWN)
			data->zoom *= 1.2;
		else if (mouse == SCROLL_UP || mouse == LEFT_CLIC)
			data->zoom /= 1.2;
		mlx_clear_window(data->mlx_ptr, data->win_ptr);
	}
	return (0);
}

void	julia_zoom(t_data *data, int mouse)
{
	if (mouse == RIGHT_CLIC || mouse == SCROLL_DOWN)
	{
		data->zoom *= 1.2;
		data->max_n++;
	}
	else if (mouse == SCROLL_UP || mouse == LEFT_CLIC)
	{
		data->zoom /= 1.2;
		data->max_n--;
	}
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	julia(data);
}

int	keys(int key, t_data *data)
{
	if (key == ESCAPE)
		exit(1);
	else if (key == 18)
		data->color = 0x00ff00;
	else if (key == 19)
		data->color = 0xff69b4;
	else if (key == 20)
		data->color = 0xffdab9;
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	if (data->fractol == 0)
		mandelbrot(data);
	else if (data->fractol == 1)
		julia(data);
	return (0);
}
