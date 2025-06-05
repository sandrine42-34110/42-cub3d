/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sapupier <sapupier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 07:32:53 by sapupier          #+#    #+#             */
/*   Updated: 2024/11/18 17:12:42 by sapupier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		c += 32;
	return (c);
}
/*
int	main(void)
{
	int	c;
	int	d;

	c = 'A';
	printf("%d\n", ft_tolower(c));
	printf("%d\n", tolower(c));
	d = 'z';
	printf("%d\n", ft_tolower(d));
	printf("%d\n", tolower(d));
	return (0);
}*/
