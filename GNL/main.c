/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocblande <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/21 19:50:32 by ocblande          #+#    #+#             */
/*   Updated: 2017/03/21 20:01:22 by ocblande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"

int	main(int ac, char **av)
{
	int fd;
	char **line;
	fd = open(av[0], O_RDONLY);
	get_next_line(fd, line);
	printf("%s", *line);
	return (0);
}
