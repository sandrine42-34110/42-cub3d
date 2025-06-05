/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sapupier <sapupier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 11:33:30 by sapupier          #+#    #+#             */
/*   Updated: 2024/11/18 17:21:31 by sapupier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Permet de comparer les 'n' premiers caracteres de s1 et s2. Si les chaines 
// sont identiques, la fonction retourne 0. 
// Principalement utilisee pour des donnees non null ou des blocs binaires
// (contrairement a strcmp plus adapter p/comparer des chaines de caracteres 
// terminees par un caractere nul ('\0').
int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t				i;
	unsigned char		*d;
	unsigned char		*s;

	i = 0;
	d = (unsigned char *)s1;
	s = (unsigned char *)s2;
	while (i < n)
	{
		if (d[i] != s[i])
		{
			return (d[i] - s[i]);
		}
		i++;
	}
	return (0);
}
/*
#include <unistd.h>
#include <stdio.h>

int	main(void)
{
	char	tab[] = "Bonjour";
	char	tab2[] = "Bons";
	printf("%d\n",ft_memcmp(tab, tab2, 6));
	printf("%d\n",memcmp(tab, tab2, 6));
}*/
