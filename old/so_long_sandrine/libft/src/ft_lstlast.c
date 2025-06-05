/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sapupier <sapupier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 08:27:04 by sapupier          #+#    #+#             */
/*   Updated: 2024/11/20 09:43:27 by sapupier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Renvoie le dernier element de la liste
t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
	{
		lst = lst->next;
	}
	return (lst);
}

// #include <stdio.h>
// int    main()
// {
//     t_list    **lst;
//     t_list    *lstclst01;
//     t_list    *lstclst02;
//     t_list    *lstclst03;
//     t_list    *lstclst04;
//     lstclst02 = ft_lstnew("bonjour");
//     lstclst01 = ft_lstnew("hello");
//     lstclst03 = ft_lstnew("comment");
//     lstclst04 = ft_lstnew("ca va");
// 	lst = &lstclst02;
// 	ft_lstadd_front(lst, lstclst01);
// 	ft_lstadd_front(lst, lstclst03);
//     ft_lstadd_front(lst, lstclst04);
// 	//ft_lstsize(*lst);
// 	printf("%s\n", (char *)ft_lstlast(*lst)->next);
//     return (0);
// }