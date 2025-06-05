/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sapupier <sapupier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 13:58:35 by sapupier          #+#    #+#             */
/*   Updated: 2024/11/13 08:02:44 by sapupier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}
/*
# include <ctype.h>
# include <unistd.h>
# include <stdio.h>

int     main(void)
{
        int     c;
        c = 'A';
        printf("%d\n", ft_isdigit(c));
        printf("%d\n", isdigit(c));
        int     d;
        d = '1';
        printf("%d\n", ft_isdigit(d));
        printf("%d\n", isdigit(d));
        return (0);
}*/
