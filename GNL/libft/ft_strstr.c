/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocblande <ocblande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 13:10:34 by ocblande          #+#    #+#             */
/*   Updated: 2016/11/26 18:02:01 by ocblande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strstr(const char *where, const char *what)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if (what[0] == '\0')
		return ((char *)&where[0]);
	while (where[i])
	{
		while (where[i + j] == what[j] && what[j] != '\0')
			j++;
		if (what[j] == '\0')
			return ((char *)&where[i]);
		i++;
		j = 0;
	}
	return (NULL);
}
