/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sapupier <sapupier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 09:08:27 by sapupier          #+#    #+#             */
/*   Updated: 2024/11/18 17:09:41 by sapupier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Compare jusqu'a 'n' caracteres des deux chaines s1 et s2
int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (s1[i] == s2[i] && i < (n - 1) && s1[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
/*
#include <unistd.h>
#include <stdio.h>
#include <string.h>
int	main(void)
{
	printf("%d\n", ft_strncmp("ABC", "AB", 3));
	printf("%d\n", strncmp("ABC", "AB", 3));
	printf("%d\n", ft_strncmp("ABC", "AB", 2));
        printf("%d\n", strncmp("ABC", "AB", 2));
	return (0);
}*/
