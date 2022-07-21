/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trozain <trozain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 16:16:50 by trozain           #+#    #+#             */
/*   Updated: 2022/07/20 14:28:03 by trozain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int argc, char **argv)
{
	t_data	*data;

	if (argc == 2)
	{
		data = (t_data *)malloc(sizeof(t_data));
		data->mlx_ptr = mlx_init();
		data->win_ptr = mlx_new_window(data->mlx_ptr, 1100, 1100, "Fractol");
		if ((fract_select(argv, data)) == 0)
			return (-1);
		mlx_key_hook(data->win_ptr, keys, data);
		mlx_hook(data->win_ptr, 17, 1L << 0, closemouse, data);
		mlx_hook(data->win_ptr, 4, 0, mouse_hook, data);
		mlx_loop(data->mlx_ptr);
		free(data);
	}
	else if (argc > 2)
		ft_putendl("Oh calme! parles pas autant ._.");
	else
		ft_putendl("rappelle: ./fractol [mandelbrot] ou [julia]");
}

int	fract_select(char **argv, t_data *data)
{
	if (ft_strcmp(argv[1], "mandelbrot") == 0)
	{
		data->fractol = 0;
		mandelbrot_init(data);
	}
	else if (ft_strcmp(argv[1], "julia") == 0)
	{
		data->fractol = 1;
		julia_init(data);
	}
	else
	{
		ft_putendl("Utilisation: ./fractol [julia] ou [mandelbrot] UwU");
		return (0);
	}
	return (1);
}

void	put_text(t_data *data)
{
	char	*text;
	char	*nb;

	nb = ft_itoa(data->max_n);
	text = ft_strjoin("Number of iterations : ", nb);
	mlx_string_put(data->mlx_ptr, data->win_ptr, 10, 10, 0xFFFFFF, text);
	ft_strdel(&text);
	ft_strdel(&nb);
}

int	closemouse(t_data data)
{
	(void) data;
	exit(1);
}
