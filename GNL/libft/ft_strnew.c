/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocblande <ocblande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 11:55:26 by ocblande          #+#    #+#             */
/*   Updated: 2016/11/29 16:36:49 by ocblande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>

char	*ft_strnew(size_t size)
{
	char	*str;
	size_t	i;

	i = 0;
	if ((str = (char *)malloc(sizeof(char) * (size + 1))) == NULL)
		return (NULL);
	while (i <= size)
	{
		str[i] = '\0';
		i++;
	}
	return (str);
}
