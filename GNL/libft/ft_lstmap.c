/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocblande <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 14:53:15 by ocblande          #+#    #+#             */
/*   Updated: 2016/12/03 18:18:53 by ocblande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *new;
	t_list *tmp;

	if ((new = (t_list *)malloc(sizeof(t_list))) == NULL)
		return (NULL);
	new = ft_lstnew(f(lst)->content, f(lst)->content_size);
	tmp = new;
	lst = lst->next;
	while (lst)
	{
		tmp->next = ft_lstnew(f(lst)->content, f(lst)->content_size);
		tmp = tmp->next;
		lst = lst->next;
	}
	tmp->next = NULL;
	return (new);
}
