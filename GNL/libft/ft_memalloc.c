/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocblande <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 15:32:22 by ocblande          #+#    #+#             */
/*   Updated: 2016/11/26 17:46:47 by ocblande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>

void	*ft_memalloc(size_t size)
{
	size_t	i;
	void	*vide;

	i = 0;
	if ((vide = (void *)malloc(sizeof(void) * size)) == NULL)
		return (NULL);
	while (i < size)
	{
		((char *)vide)[i] = 0;
		i++;
	}
	return (vide);
}
