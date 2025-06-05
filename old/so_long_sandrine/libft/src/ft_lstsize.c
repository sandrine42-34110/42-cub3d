/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sapupier <sapupier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 07:55:57 by sapupier          #+#    #+#             */
/*   Updated: 2024/11/20 08:21:58 by sapupier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Compte le nb d elements de la liste

int	ft_lstsize(t_list *lst)
{
	int	count;

	count = 0;
	while (lst)
	{
		lst = lst->next;
		count ++;
	}
	return (count);
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
// 	ft_lstsize(*lst);
// 	printf("%d\n", ft_lstsize(*lst));
//     return (0);
// }
