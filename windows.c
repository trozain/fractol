/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   windows.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trozain <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 15:04:24 by trozain           #+#    #+#             */
/*   Updated: 2022/06/30 15:34:58 by trozain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx/mlx.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
	void *mlx;
	void *mlx_windows;

	mlx = mlx_init();
	mlx_windows = mlx_new_window(julia, 1920, 1080, "Hello world!");
	mlx_loop(mlx);
}
