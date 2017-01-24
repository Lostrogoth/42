/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocblande <ocblande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 13:32:12 by ocblande          #+#    #+#             */
/*   Updated: 2016/11/26 18:05:14 by ocblande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char			*ret;
	unsigned int	i;
	int				j;

	j = 0;
	i = start + len;
	if (s == NULL)
		return (NULL);
	if ((ret = (char *)malloc(sizeof(char) * len + 1)) == NULL)
		return (NULL);
	while (start < i)
	{
		ret[j] = s[start];
		j++;
		start++;
	}
	ret[j] = '\0';
	return (ret);
}
