/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocblande <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 16:59:55 by ocblande          #+#    #+#             */
/*   Updated: 2016/11/26 17:58:27 by ocblande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <string.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	char*ret;
	int i;
	int j;

	j = 0;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	i = ft_strlen(s1) + ft_strlen(s2);
	if ((ret = (char *)malloc(sizeof(ret) * i)) == NULL)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		ret[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		ret[i] = s2[j];
		i++;
		j++;
	}
	ret[i] = '\0';
	return (ret);
}
