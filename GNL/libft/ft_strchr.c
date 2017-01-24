/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocblande <ocblande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 11:48:33 by ocblande          #+#    #+#             */
/*   Updated: 2016/11/26 17:56:47 by ocblande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

char	*ft_strchr(const char *s, int c)
{
	int i;

	i = -1;
	while (s[i] || i == -1)
	{
		i++;
		if (s[i] == c)
			return ((char *)&s[i]);
	}
	return (NULL);
}
