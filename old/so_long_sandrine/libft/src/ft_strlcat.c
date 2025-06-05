/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sapupier <sapupier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 08:27:19 by sapupier          #+#    #+#             */
/*   Updated: 2024/11/13 08:07:54 by sapupier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// La fonction strlcat ajoute la chaine src a la fin de la chaine dest, mais
// elle veille a ne pas depasser la taille du tampon dest
// Retourne la long totale de dest apres la concatenation si l espace le permet
// ou la longueur de src + size si le tampon est trop petit.

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	nb_dest;
	size_t	len_dst;	

	nb_dest = ft_strlen(src) + ft_strlen(dst);
	len_dst = ft_strlen(dst);
	if (size == 0 || size <= len_dst)
		return (ft_strlen(src) + size);
	i = 0;
	while ((len_dst + i < (size - 1)) && src[i])
	{
		dst[len_dst + i] = src[i];
		i++;
	}
	dst[len_dst + i] = '\0';
	return (nb_dest);
}
/*
int	main(void)
{
	char dst[50] = "Firststring";
	const char src[] = "Secon";
	printf("%ld\n", strlcat(dst, src, 5));
	//printf("%ld\n", ft_strlcat(dst, src, 6));
	//ft_strlcat(dst, src, 50);
	//printf("New : %s\n", dst);
	return (0);
}*/
