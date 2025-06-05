/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sapupier <sapupier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 14:16:11 by sapupier          #+#    #+#             */
/*   Updated: 2024/11/13 08:00:08 by sapupier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')
		|| (c >= '0' && c <= '9'))
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
        printf("%d\n", ft_isalnum(c));
        printf("%d\n", isalnum(c));
        int     d;
        d = '1';
        printf("%d\n", ft_isalnum(d));
        printf("%d\n", isalnum(d));
        return (0);
}
*/
