/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sapupier <sapupier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 16:29:03 by sapupier          #+#    #+#             */
/*   Updated: 2024/11/13 08:05:42 by sapupier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		c -= 32;
	return (c);
}
/*
int     main(void)
{
	int     c;
	c = 'A';
	printf("%d\n", ft_toupper(c));
	printf("%d\n", toupper(c));
	int     d;
	d = 'z';
	printf("%d\n", ft_toupper(d));
	printf("%d\n", toupper(d));
	return (0);
}
*/
