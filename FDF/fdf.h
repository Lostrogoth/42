/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocblande <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/13 16:49:25 by ocblande          #+#    #+#             */
/*   Updated: 2017/10/04 17:34:44 by ocblande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# define HEIGHT 1000
# define WIDTH 1000
#include "minilibx_macos/mlx.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "Libft/libft.h"

typedef struct	s_point
{
	double	x;
	double	y;
	double	z;
	double	x2;
	double	y2;
	double	z2;
}				t_point;
typedef struct	s_mlx
{
	void	*ptr;
	void	*img;
	void	*win;
	char	*imga;
	int		bpp;
	int		sl;
	int		endian;
	int		nbp;
	int		linesize;
	int		colsize;
	t_point	*map;
	int		transx;
	int		transy;
	int		xrot;
	int		yrot;
	int		zrot;
	double	zoom;
	int		color;
}				t_mlx;

t_point		*fdf_to_struct(char *file, t_mlx *fdf);
t_point		*istruft_fill(t_point *point, char *file, t_mlx *fdf);
int			error(char *line);
void		put_pixel_img(t_mlx *mlx, int x, int y, int color);
void		bresenham(t_mlx *mlx, int x1, int x2, int y1, int y2);
#endif
