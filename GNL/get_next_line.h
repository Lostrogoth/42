/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocblande <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/12 17:01:30 by ocblande          #+#    #+#             */
/*   Updated: 2017/01/17 09:43:53 by ocblande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 10

# include "libft/libft.h"
# include <unistd.h>
# include <stdlib.h>

int		get_next_line(const int fd, char **line);

#endif
