/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sapupier <sapupier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 14:35:32 by sapupier          #+#    #+#             */
/*   Updated: 2024/11/13 08:02:31 by sapupier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
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
        printf("%d\n", ft_isascii(c));
        printf("%d\n", isascii(c));
        int     d;
        d = '1';
        printf("%d\n", ft_isascii(d));
        printf("%d\n", isascii(d));
        return (0);
}*/
