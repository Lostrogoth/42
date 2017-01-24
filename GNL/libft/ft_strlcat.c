/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocblande <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 17:31:34 by ocblande          #+#    #+#             */
/*   Updated: 2016/11/26 17:58:47 by ocblande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	destlen;
	size_t	srclen;

	destlen = ft_strlen(dest);
	srclen = ft_strlen(src);
	if (size <= ft_strlen(dest))
		return (size + srclen);
	else
	{
		ft_strncat(dest, src, size - destlen - 1);
		return (destlen + srclen);
	}
}
