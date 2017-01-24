/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocblande <ocblande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 16:21:11 by ocblande          #+#    #+#             */
/*   Updated: 2016/12/02 22:45:13 by ocblande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int i;
	int n;
	int isneg;

	i = 0;
	n = 0;
	isneg = 1;
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t' || str[i] == '\f'
			|| str[i] == '\v' || str[i] == '\r')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			isneg = -1;
		i++;
	}
	while (ft_isdigit(str[i]))
	{
		n = 10 * n + str[i] - 48;
		i++;
	}
	return (n * isneg);
}
