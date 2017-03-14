/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocblande <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 16:13:43 by ocblande          #+#    #+#             */
/*   Updated: 2017/03/14 19:46:58 by ocblande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "../LibftBonne/libft.h"

void	free_malloc(char *buf, char *str)
{
	char	*tmp;
	ft_strcpy(tmp, str);
	free(str);
	ft_strjoin(tmp, buf);
}

void	buff_to_str(char *buf, char *str, int fd)
{
	int	end;
	if ((buf = (char *)malloc(sizeof(char) * BUFF_SIZE)) == 0)
		return; //error
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
	char	*tmp;
	int			i;

	while (!ft_strchr(str, '\n'))
		buff_to_str(buf, str, fd);
	while (str[i] != '\n')
		i++;
	*line = ft_strndup(str, i);

}
