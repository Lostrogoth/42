/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocblande <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 10:58:08 by ocblande          #+#    #+#             */
/*   Updated: 2016/11/26 18:00:04 by ocblande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

char	*ft_strncat(char *dest, const char *src, size_t n)
{
	size_t i;
	size_t j;

	i = 0;
	j = 0;
	while (i < ft_strlen(dest))
		i++;
	while (src[j] && j < n)
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (dest);
}
