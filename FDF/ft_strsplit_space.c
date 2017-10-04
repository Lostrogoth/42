/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocblande <ocblande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 16:18:00 by ocblande          #+#    #+#             */
/*   Updated: 2017/08/13 16:18:29 by ocblande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>

static int	word(char const *s)
{
	int i;
	int words;

	i = 0;
	words = 0;
	while (s[i])
	{
		while (s[i] == ' ' || s[i] == '\n')
			i++;
		if (s[i] != '\0')
		{
			words++;
			while (s[i] != ' ' && s[i] != '\n' && s[i] != '\0')
				i++;
		}
	}
	return (words);
}

static int	ln(const char *s, int i)
{
	int	len;

	len = 0;
	while (s[i] != ' '  && s[i] != '\n' && s[i])
	{
		len++;
		i++;
	}
	return (len);
}

char		**ft_strsplit_space(char const *s)
{
	char	**tab;
	int		i;
	int		w;
	int		cha;

	i = 0;
	w = 0;
	if (!s || (tab = (char **)malloc(sizeof(char*) * word(s) + 1)) == NULL)
		return (NULL);
	while (s[i])
	{
		while (s[i] == ' ' || s[i] == '\n')
			i++;
		if (s[i] != '\0')
		{
			if ((tab[w] = (char *)malloc(sizeof(char) * ln(s, i) + 1)) == 0)
				return (NULL);
			cha = 0;
			while (s[i] && s[i] != ' ' && s[i] != '\n')
				tab[w][cha++] = s[i++];
			tab[w++][cha] = '\0';
		}
	}
	tab[w] = NULL;
	return (tab);
}
