/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocblande <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 20:31:43 by ocblande          #+#    #+#             */
/*   Updated: 2016/12/05 18:57:14 by ocblande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	**ft_tabnew(int i, int j, char c)
{
	int		n;
	char	**tab;

	n = 0;
	if ((tab = (char **)malloc(sizeof(char*) * (i + 1))) == NULL)
		return (NULL);
	tab[i] = NULL;
	while (n < i)
	{
		if ((tab[n] = (char *)malloc(sizeof(char) * (j + 1))) == NULL)
			return (NULL);
		ft_memset(tab[n], c, j);
		tab[n][j] = '\0';
		n++;
	}
	return (tab);
}
