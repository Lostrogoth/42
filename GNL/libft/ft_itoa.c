/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocblande <ocblande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 12:28:25 by ocblande          #+#    #+#             */
/*   Updated: 2016/11/26 17:52:57 by ocblande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <string.h>

static char	*intostr(int n, char *str, int mal)
{
	str[mal + 1] = '\0';
	if (n < 0)
		str[0] = '-';
	n = ABS(n);
	while (n >= 10)
	{
		str[mal] = n % 10 + 48;
		n = n / 10;
		mal--;
	}
	str[mal] = n % 10 + 48;
	return (str);
}

char		*ft_itoa(int n)
{
	int		i;
	int		mal;
	char	*str;

	mal = 0;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if ((i = ABS(n)) != n)
		mal++;
	while (i >= 10)
	{
		mal++;
		i = i / 10;
	}
	if ((str = (char *)malloc(sizeof(char) * (mal + 2))) == NULL)
		return (NULL);
	intostr(n, str, mal);
	return (str);
}
