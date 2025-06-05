/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sapupier <sapupier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 12:11:25 by sapupier          #+#    #+#             */
/*   Updated: 2024/11/13 08:01:46 by sapupier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	return (0);
}
/*
# include <ctype.h>
# include <unistd.h>
# include <stdio.h>

int	main(void)
{
	int	c;
	c = 'A';
	printf("%d\n", ft_isalpha(c));
	printf("%d\n", isalpha(c));
	int     d;
        d = ' ';
        printf("%d\n", ft_isalpha(d));
        printf("%d\n", isalpha(d));
	return (0);
}*/
