/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sapupier <sapupier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 14:43:04 by sapupier          #+#    #+#             */
/*   Updated: 2024/11/13 08:02:53 by sapupier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
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
        c = ' ';
	printf("%d\n", ft_isprint(c));
        printf("%d\n", isprint(c));
        int     d;
        d = 127;
        printf("%d\n", ft_isprint(d));
        printf("%d\n", isprint(d));
        return (0);
}
*/
