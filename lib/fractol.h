/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trozain <trozain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 15:46:20 by trozain           #+#    #+#             */
/*   Updated: 2022/07/21 20:13:55 by trozain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <unistd.h>
# include <math.h>
# include "../libft/libft.h"
# include "../minilibx/mlx.h"

typedef struct s_data
{
	void		*mlx_ptr;
	void		*win_ptr;
	int			fractol;
	int			color;
	int			width;
	int			height;
	double		min_x;
	double		max_x;
	double		min_y;
	double		max_y;
	double		cre;
	double		cim;
	double		new_x;
	double		new_y;
	double		oldre;
	double		oldim;
	double		zoom;
	double		max_n;
	int			random;
}				t_data;

/*
		main
*/

int		closemouse(t_data data);
int		fract_select(char **argv, t_data *data);
void	put_text(t_data *data);

/*
		julia
*/

void	julia(t_data *data);
void	julia_init(t_data *data);
void	julia_zoom(t_data *data, int mousecode);
int		julia_x(t_data *data);

/*
		mandelbrot
*/

void	mandelbrot_init(t_data *data);
int		find_n(double cr, double ci, double max_n);
void	mandelbrot(t_data *data);
double	find_real(int x, t_data *data);
double	find_imaginary(int y, t_data *data);

/*
		fractol1 (keys buttons hook etc)
*/

void	ft_zoom(int x, int y, t_data *data);
void	ft_dezoom(int x, int y, t_data *data);
int		keys(int key, t_data *data);
int		mouse_hook(int mousecode, int x, int y, t_data *data);

#endif
