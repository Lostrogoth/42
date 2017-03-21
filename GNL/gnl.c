/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocblande <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 16:13:43 by ocblande          #+#    #+#             */
/*   Updated: 2017/03/21 20:02:24 by ocblande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "../LibftBonne/libft.h"

void	free_malloc(char *buf, char *str)
{
	char	*tmp;
	tmp = ft_strdup(str);
	free(str);
	str = ft_strjoin(tmp, buf);
}

void	buff_to_str(char *buf, char *str, int fd)
{
	int	end;
	if ((end = read(fd, buf, BUFF_SIZE)) == 0)
		return; // fin ? / error
	buf[end] = '\0';
	if (str)
		free_malloc(buf, str);
	else
		str = ft_strdup(buf);
}

int		get_next_line(const int fd, char **line)
{
	char		buf[BUFF_SIZE + 1];
	static char	*str;
	char		*tmp;
	int			i;
	int			j;

	i = 0;
	j = 0;
	while (!ft_strchr(str, '\n'))
		buff_to_str(buf, str, fd);
	while (str[i] != '\n')
		i++;
	*line = ft_strndup(str, i);
	if ((tmp = (char *)malloc(sizeof(char) * (ft_strlen(str) - i))) == 0)
		return 0; //error;
	i++;
	while (str[i + j] != '\0')
	{
		tmp[j] = str[i + j];
		j++;
	}
	tmp[j] = '\0';
	free(str);
	str = ft_strdup(tmp);
	free(tmp);
	return (0);
}
