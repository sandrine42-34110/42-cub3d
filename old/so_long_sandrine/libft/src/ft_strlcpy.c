/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sapupier <sapupier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 09:12:56 by sapupier          #+#    #+#             */
/*   Updated: 2024/11/19 15:36:39 by sapupier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// Copie la chaine src dans la chaine dest, mais elle s assure que la chaine
// copiee ne depasse pas la taille max specifiee par size.
// Si chaine copiee + longue que size-1, dest tj terminee par '\0'
// La fonction retourne la long totale de la chaine source (avt coupe event)
// ce qui permet de savoir si chaine a ete coupee 
size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size == 0)
		return (ft_strlen(src));
	while (i < (size - 1) && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (ft_strlen(src));
}
/*
#include <bsd/string.h>
#include <stdio.h>i
int	main(void)
{
	char dst[] = "fr";
	const char src[] = "Secondstring"; 
	printf("%ld\n", ft_strlcpy(dst, src, 2));
	printf("%ld\n", strlcpy(dst, src, 2));
//	ft_strlcpy(dst, src, 2);
//	printf("New : %s\t%s\n", dst, src);
	strlcpy(dst, src, 2);
	printf("New : %s\t%s\n", dst, src);
	//printf("%ld\n", strlcpy(dst, src, 5));
	return (0);
}*/
