/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocblande <ocblande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 15:08:24 by ocblande          #+#    #+#             */
/*   Updated: 2016/12/05 18:54:32 by ocblande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memset(void *s, int c, size_t n)
{
	while (n)
	{
		((unsigned char *)s)[n - 1] = (unsigned char)c;
		n--;
	}
	return (s);
}
