/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenmam.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocblande <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/13 18:32:39 by ocblande          #+#    #+#             */
/*   Updated: 2017/09/30 19:01:20 by ocblande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fdf.h"

void put_pixel_img(t_mlx *mlx, int x, int y, int color)
{
	x += WIDTH / 2;
	y += HEIGHT / 2;
	if (x < HEIGHT && y < WIDTH && x >= 0 && y >= 0)
		*(unsigned *)(mlx->imga + mlx->sl * (y + mlx->transy) + (mlx->bpp / 8) * (x + mlx->transx)) = color;
}

void	bresenham(t_mlx *mlx, int x1, int x2, int y1, int y2)
{
	int	dx = abs(x2 - x1);
	int	sx = x1 < x2 ? 1 : -1;
	int	dy = -abs(y2 - y1);
	int	sy = y1 < y2 ? 1 : -1;
	int	err = dx + dy;
	int	e2;
	while (1)
	{
		put_pixel_img(mlx, x1, y1, mlx->color);
		if (x1 == x2 && y1 == y2)
			return ;
		e2 = 2 * err;
		if (e2 >= dy) 
		{
			err += dy;
			x1 += sx;
		}
		if (e2 <= dx)
		{
			err += dx;
			y1 += sy;
		}
	}
}
