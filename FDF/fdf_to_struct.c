#include "fdf.h"


t_point		*struft_fill(t_point *point, char *file, t_mlx *fdf)
{
	int		x;
	int		y;
	int		fd;
	char	*line;
	char	**split;
	x = 0;
	y = 0;
	fd = 0;
	if ((fd = open(file, O_RDONLY)) == -1)
		return (NULL);
	while (get_next_line(fd, &line) > 0)
	{
		split = ft_strsplit(line, ' ');
		while(split[x])
		{
			point[x + y * fdf->linesize].x = (double)x - (double)fdf->linesize / 2+ 0.5;
			point[x + y * fdf->linesize].y = (double)y - (double)fdf->colsize / 2 + 0.5;
			point[x + y * fdf->linesize].z = (double)ft_atoi(split[x]);
			x++;
		}
		x = 0;
		y++;
	}
	return (point);
}


int		error(char *file)
{
	int		i;
	char*	line;
	int		fd;

	i = 0;
	if ((fd = open(file, O_RDONLY)) == -1)
		return (1);
	while (get_next_line(fd, &line) > 0)
	{
		while (line[i])
		{
			if (!ft_isdigit(line[i]))
				return (1);
			while(ft_isdigit(line[i]))
				i++;
			if (line[i] != ' ' || line[i] != '\n')
				return (1);
			i++;
		}
		i = 0;
	}
	return (0);
}


t_point		*fdf_to_struct(char *file, t_mlx *fdf)
{
	t_point	*point;
	int		i;
	char	buf;
	int		fd;
	fdf->linesize = 0;
	i = 0;
	fd = 0;
	if ((fd = open(file, O_RDONLY)) == -1)
		return (NULL);
	while (read(fd, &buf, 1))
	{
		if (buf == ' ' || buf == '\n')
			i++;
		if (buf == '\n' && !fdf->linesize)
			fdf->linesize = i;
	}
	close (fd);
	fdf->colsize = i / fdf->linesize;
	if ((point = (t_point *)malloc(sizeof(t_point) * i)) == NULL)
		return (NULL);
	return (struft_fill(point, file, fdf));
}
