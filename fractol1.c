/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trozain <trozain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 15:01:45 by trozain           #+#    #+#             */
/*   Updated: 2022/07/18 16:08:02 by trozain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_zoom(int x, int y, t_data *data)
{
	data->minreal = (x / data->zoom + data->minreal) - (x / (data->zoom * 1.2));
	data->min_i = (y / data->zoom + data->min_i) - (y / (data->zoom * 1.2));
	data->zoom *= 1.2;
	data->max_n++;
}

void	ft_dezoom(int x, int y, t_data *data)
{
	data->minreal = (x / data->zoom + data->minreal) - (x
			/ (data->zoom / 1.2));
	data->min_i = (y / data->zoom + data->min_i) - (y / (data->zoom / 1.2));
	data->zoom /= 1.2;
	data->max_n--;
}

int	mouse_hook(int mousecode, int x, int y, t_data *data)
{
	if (data->fractol == 0)
	{
		if (mousecode == 5 || mousecode == 2)
			ft_zoom(x, y, data);
		else if (mousecode == 4 || mousecode == 1)
			ft_dezoom(x, y, data);
		mlx_clear_window(data->mlx_ptr, data->win_ptr);
		mandelbrot(data);
	}
	else if (data->fractol == 1)
		zoom_julia(data, mousecode);
	put_text(data);
	if (data->fractol == 2)
	{
		if (mousecode == 2 || mousecode == 5)
			data->zoom *= 1.2;
		else if (mousecode == 4 || mousecode == 1)
			data->zoom /= 1.2;
		mlx_clear_window(data->mlx_ptr, data->win_ptr);
	}
	return (0);
}

void	zoom_julia(t_data *data, int mousecode)
{
	if (mousecode == 2 || mousecode == 5)
	{
		data->zoom *= 1.2;
		data->max_n++;
	}
	else if (mousecode == 4 || mousecode == 1)
	{
		data->zoom /= 1.2;
		data->max_n--;
	}
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	julia(data);
}

int	keys(int key, t_data *data)
{
	if (key == 53)
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
