/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocblande <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 16:18:01 by ocblande          #+#    #+#             */
/*   Updated: 2016/11/26 17:53:37 by ocblande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*caca;
	size_t			i;

	i = 0;
	caca = (unsigned char*)s;
	while (i < n)
	{
		if (*caca == (unsigned char)c)
			return ((void*)caca);
		caca++;
		i++;
	}
	return (NULL);
}
