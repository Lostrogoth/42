/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocblande <ocblande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 13:19:42 by ocblande          #+#    #+#             */
/*   Updated: 2016/11/26 17:59:51 by ocblande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <string.h>

char	*ft_strmapi(char const *s, char (*f) (unsigned int, char))
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
		res[i] = f(i, s[i]);
		i++;
	}
	res[i] = '\0';
	return (res);
}
