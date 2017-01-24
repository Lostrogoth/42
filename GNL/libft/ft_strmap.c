/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocblande <ocblande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 13:13:39 by ocblande          #+#    #+#             */
/*   Updated: 2016/11/26 17:59:32 by ocblande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>
#include <stdlib.h>

char	*ft_strmap(char const *s, char (*f) (char))
{
	int i;
	char*res;

	i = 0;
	if (s == NULL || f == NULL)
		return (NULL);
	if ((res = (char *)malloc(sizeof(char) * ft_strlen(s) + 1)) == NULL)
		return (NULL);
	while (s[i])
	{
		res[i] = f(s[i]);
		i++;
	}
	res[i] = '\0';
	return (res);
}
