/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sapupier <sapupier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 14:12:08 by sapupier          #+#    #+#             */
/*   Updated: 2024/11/19 09:19:25 by sapupier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// La fonction memcpy copie exactement n octets de la memoire pointee par src
// vers la memoire pointee par dest.
// La fonction memcpy renvoie un pointeur sur dest
void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*d;
	unsigned char		*s;

	i = 0;
	s = (unsigned char *)src;
	d = (unsigned char *)dest;
	if (src == 0 && dest == 0)
		return (NULL);
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (dest);
}
/*
#include <string.h>
#include <stdio.h>
int     main(void)
{
	char dest[] = "Firstring";
	const char src[] = "Secondstring";
	ft_memcpy(dest, src, 5);
	printf("New arrays : %s\t%s\n", dest, src);
	memcpy(dest, src, 5);
	printf("New arrays : %s\t%s\n", dest, src);
   return (0);
}*/