/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sapupier <sapupier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 12:08:21 by sapupier          #+#    #+#             */
/*   Updated: 2024/11/20 07:53:11 by sapupier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Sert a ajouter l element 'new' au debut de la liste. lst = adresse du 
// pointeur vers le 1er element de la liste. new = adresse du pointeur vers 
// l element a rajouter a la liste
void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return ;
	new->next = *lst;
	*lst = new;
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
//     printf("%s\n", (char *)(lstclst02->content));
//     lstclst01 = ft_lstnew("hello");
//     printf("%p\n", lstclst01);
//     lstclst03 = ft_lstnew("test");
//     lstclst04 = ft_lstnew("avant test");
//     printf("%p\n", lstclst03);
//     lst = &lstclst02;
//     printf("%p\n",lst);
//     ft_lstadd_front(lst, lstclst01);
//     ft_lstadd_front(lst, lstclst04);
//     ft_lstadd_front(lst, lstclst03);
//     printf("%p\n", lst);
//     while (lst)
//     {
//         printf("%s\n", (char *)(*lst)->content);
//         *lst = (*lst)->next;
//     }
//     return (0);
// }