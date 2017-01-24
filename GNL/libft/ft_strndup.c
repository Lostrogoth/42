/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocblande <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 18:52:23 by ocblande          #+#    #+#             */
/*   Updated: 2016/12/05 18:51:58 by ocblande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>

char	*ft_strndup(const char *str, size_t n)
{
	char	*dup;
	int		i;
	size_t	end;

	end = 0;
	i = 0;
	while (str[end] && end < n)
		end++;
	if ((dup = (char *)malloc(sizeof(char) * end + 1)) == NULL)
		return (NULL);
	while (str[i] && end)
	{
		dup[i] = str[i];
		i++;
		end--;
	}
	dup[i] = '\0';
	return (dup);
}
