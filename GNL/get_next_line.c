/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocblande <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/12 16:44:32 by ocblande          #+#    #+#             */
/*   Updated: 2017/01/17 09:43:45 by ocblande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		str_alloc(char *str, int i)
{
	if ((str = (char *)malloc(sizeof(char) * (i + 1))) == NULL)
		return (0);
	return (1);
}

void	line_filler(char *str, int i, char **line)
{
	
}

void	static_rest(char *str, char **line)
{
	int		i;
	char	*tmp;

	i = 0;
	while (str[i])
	{
		if (str[i]  == '\n')
		{
			line_filler(str, i, line);
			if (str[i + 1] != '\0')
			{
				ft_strcpy(tmp, &str[i + 1]);
				free(str);
				if ((str = (char *)malloc(sizeof(char) *
						(ft_strlen(tmp + 1)))) == NULL)
							error
				ft_strcpy(str, tmp);
			}
		}
		i++;
	}
}

int		get_next_line(const int fd, char **line)
{
	char		buf[BUFF_SIZE + 1];
	static char	*str;
	int			i;
	int			end;

	i = 0;
	if (!str || ft_strlen(str) == BUFF_SIZE)
	{
		if(end = read(fd, buf, BUFF_SIZE) == 0)
			return (0);
		buf[BUFF_SIZE] = '\0';
		while (buf[i])
		{
			if (buf[i] == '\n')
			{

				if ((*line = (char *)malloc(sizeof(char) * (i + 1))) == NULL)
					return (-1);
				ft_strncpy((char *)line, buf, i);
				*line[i] = '\0';
				i++;
				if (buf[i])
				{
					if ((str = (char *)malloc(sizeof(char) *
							(BUFF_SIZE - i + 1))) == NULL)
						return (-1);
				}
				while (buf[i + j])
				{
					str[j] = buf[i + j];
					j++;
				}
				str[j] = '\0';
				return (1);
			i++;
		}

	}




	if (ft_strchr(buf, '\n') != NULL)
	{
		
	}
}
