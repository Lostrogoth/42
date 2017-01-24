/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocblande <ocblande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 17:08:30 by ocblande          #+#    #+#             */
/*   Updated: 2016/11/26 18:02:22 by ocblande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>
#include <stdlib.h>

char	*ft_strtrim(char const *s)
{
	int	beg;
	int	end;
	int i;
	char*ret;
	int	blank;

	blank = 0;
	beg = 0;
	end = 0;
	i = 0;
	if (s == NULL)
		return (NULL);
	while (s[beg] == ' ' || s[beg] == '\n' || s[beg] == '\t')
		beg++;
	end = ft_strlen(s) - 1;
	while (s[end] == ' ' || s[end] == '\n' || s[end] == '\t')
		end--;
	if (s[beg] == '\0')
		blank = 1 + end - beg;
	if ((ret = (char *)malloc(sizeof(char) * (end - beg + 2 - blank))) == NULL)
		return (NULL);
	while (beg <= end)
		ret[i++] = s[beg++];
	ret[i] = '\0';
	return (ret);
}
