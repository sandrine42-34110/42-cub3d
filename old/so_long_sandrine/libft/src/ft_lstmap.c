/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sapupier <sapupier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 10:52:57 by sapupier          #+#    #+#             */
/*   Updated: 2024/11/20 12:22:22 by sapupier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Itère sur la liste ’lst’ et applique la fonction ’f ’au contenu de chaque
// élément. Crée une nouvelle liste résultant des applications successives de
// ’f’. La fonction ’del’ est là pour détruire le contenu d’un élément 
// si nécessaire.
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*dest_list;
	t_list	*new_node;

	dest_list = NULL;
	while (lst != NULL)
	{
		new_node = ft_lstnew(f(lst->content));
		if (!new_node)
		{
			ft_lstclear(&dest_list, del);
			return (NULL);
		}
		ft_lstadd_back(&dest_list, new_node);
		lst = lst->next;
	}
	return (dest_list);
}
