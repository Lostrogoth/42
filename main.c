/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocblande <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/13 16:47:57 by ocblande          #+#    #+#             */
/*   Updated: 2017/10/04 19:24:14 by ocblande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
void	printmap(t_mlx *fdf);

void	save(t_mlx *fdf)
{
	int	i;
	i = 0;
	while (i < fdf->colsize * fdf->linesize)
	{
		fdf->map[i].x2 = fdf->map[i].x;
		fdf->map[i].y2 = fdf->map[i].y;
		fdf->map[i].z2 = fdf->map[i].z;
		i++;
	}
}

void	rotateX(t_mlx *fdf)
{
	int	i;
	double	tmp;

	i = 0;
	while (i < fdf->colsize * fdf->linesize)
	{
		tmp = fdf->map[i].y * (double)cos((fdf->xrot * M_PI) / 180) - fdf->map[i].z * (double)sin((fdf->xrot * M_PI) / 180);
		fdf->map[i].z = fdf->map[i].y * (double)sin((fdf->xrot * M_PI) / 180) + fdf->map[i].z * (double)cos((fdf->xrot * M_PI) / 180);
		fdf->map[i].y = tmp;
		i++;
	}
}

void	rotateY(t_mlx *fdf)
{
	int	i;
	double	tmp;

	i = 0;
	while (i < fdf->colsize * fdf->linesize)
	{
		tmp = fdf->map[i].x * (double)cos((fdf->yrot * M_PI) / 180) + fdf->map[i].z * (double)sin((fdf->yrot * M_PI) / 180);
		fdf->map[i].z = fdf->map[i].x * -(double)sin((fdf->yrot * M_PI) / 180) + fdf->map[i].z * (double)cos((fdf->yrot * M_PI) / 180);
		fdf->map[i].x = tmp;
		i++;
	}
}

void	rotateZ(t_mlx *fdf)
{
	int	i;
	double	tmp;

	i = 0;
	while (i < fdf->colsize * fdf->linesize)
	{
		tmp = fdf->map[i].x * (double)cos((fdf->zrot * M_PI) / 180) - fdf->map[i].y * (double)sin((fdf->zrot * M_PI) / 180);
		fdf->map[i].y = fdf->map[i].x * (double)sin((fdf->zrot * M_PI) / 180) + fdf->map[i].y * (double)cos((fdf->zrot * M_PI) / 180);
		fdf->map[i].x = tmp;
		i++;
	}
}

void	riset(t_mlx *fdf)
{
	int	i;
	i = 0;
	while (i < fdf->colsize * fdf->linesize)
	{
		fdf->map[i].x = fdf->map[i].x2 * fdf->zoom;
		fdf->map[i].y = fdf->map[i].y2 * fdf->zoom;
		fdf->map[i].z = fdf->map[i].z2 * fdf->zoom;
	i++;
	}
	rotateX(fdf);
	rotateY(fdf);
	rotateZ(fdf);
}

int key_hook(int keycode, t_mlx *fdf)
{
mlx_destroy_image(fdf->ptr, fdf->img);
fdf->img = mlx_new_image(fdf->ptr, WIDTH, HEIGHT);
	if (keycode == 53)
	{
		mlx_destroy_window(fdf->ptr, fdf->win);
		exit(1);
	}
	if (keycode == 69)
	{
		fdf->zoom *= 2;
		riset(fdf);
	}
	if (keycode == 78)
	{
		fdf->zoom /= 2;
		riset(fdf);
	}
	if (keycode == 126)
		fdf->transy -= 10;
	if (keycode == 125)
		fdf->transy += 10;
	if (keycode == 123)
		fdf->transx -= 10;
	if (keycode == 124)
		fdf->transx += 10;
	if (keycode == 91)
	{
		fdf->xrot += 10;
		riset(fdf);;
	}
	if (keycode == 84)
	{
		fdf->xrot -= 10;
		riset(fdf);
	}
	if (keycode == 86)
	{
		fdf->yrot -= 10;
		riset(fdf);
	}
	if (keycode == 88)
	{
		fdf->yrot += 10;
		riset(fdf);
	}
	if (keycode == 92)
	{
		fdf->zrot += 10;
		riset(fdf);
	}
	if (keycode == 83)
	{
		fdf->zrot -= 10;
		riset(fdf);
	}
	if (keycode == 12)
		fdf->color = 0XFFFFFF;
	if (keycode == 13)
		fdf->color = 0XFF0000;
	if (keycode == 14)
		fdf->color = 0X0000FF;
	if (keycode == 15)
		fdf->color = 0X00FF00;
	if (keycode == 17)
		fdf->color = 0X00FFFF;
	if (keycode == 16)
		fdf->color = 0XFF00FF;
	if (keycode == 32)
		fdf->color = 0XFFFF00;
	printmap(fdf);
	return(0);
}

void printmap(t_mlx *fdf)
{
	int i;

	i = 0;
	while (i < fdf->colsize *  fdf->linesize)
	{
		if ((i + 1) % fdf->linesize)
			bresenham(fdf, (int)fdf->map[i].x, (int)fdf->map[i + 1].x, (int)fdf->map[i].y			, (int)fdf->map[i + 1].y);
		if ((i / fdf->linesize) + 1 < fdf->colsize)
			bresenham(fdf, (int)fdf->map[i].x, (int)fdf->map[i + fdf->linesize].x,
				(int)fdf->map[i].y, (int)fdf->map[i + fdf->linesize].y);
	i++;
	}
	mlx_put_image_to_window(fdf->ptr, fdf->win, fdf->img, 0, 0);
}


int		main(int ac, char **av)
{
	int i;
	i = 9;
	if (ac != 2)
	{
		ft_putstr("invalid number of arguments");
	return (2);
	}
		t_mlx	fdf;
	fdf.ptr = mlx_init();
	fdf.img = mlx_new_image(fdf.ptr, WIDTH, HEIGHT);
	fdf.imga = mlx_get_data_addr(fdf.img, &(fdf.bpp), &(fdf.sl), &(fdf.endian));
	fdf.win = mlx_new_window(fdf.ptr, WIDTH, HEIGHT, "coucoutvvmb");
	mlx_key_hook(fdf.win, key_hook, &fdf);
	if (error(av[1])) 
		ft_putstr("map error");
	fdf.map = fdf_to_struct(av[1], &fdf);
	save(&fdf);
	fdf.transx = 0;
	fdf.transy = 0;
	fdf.xrot = 0;
	fdf.yrot = 0;
	fdf.zrot = 0;
	fdf.color = 0XFFFFFF;
	fdf.zoom = (HEIGHT / fdf.linesize) / 2;
	riset(&fdf);
	printmap(&fdf);
	mlx_loop(fdf.ptr);
	return (0);
}
