/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocblande <ocblande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 13:17:24 by ocblande          #+#    #+#             */
/*   Updated: 2016/11/26 18:01:04 by ocblande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strnstr(const char *where, const char *what, size_t len)
{
	size_t i;
	size_t j;

	i = 0;
	j = 0;
	if (what[0] == '\0')
		return ((char *)where);
	while (where[i])
	{
		while (where[i + j] == what[j] && (j + i) < len)
		{
			j++;
			if (what[j] == '\0')
				return ((char *)&where[i]);
		}
		i++;
		j = 0;
	}
	return (NULL);
}
