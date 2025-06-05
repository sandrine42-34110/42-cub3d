/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sapupier <sapupier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 08:10:48 by sapupier          #+#    #+#             */
/*   Updated: 2024/11/19 11:52:02 by sapupier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// Tres similaire a memcpy mais avec une diff importante : elle peut etre 
// utilisee lorsaue les zones src et des se chevauchent.
// La fonction memmove copie n octets de la memoire pointee par src vers la
// memoire pointee par dest, tt en garantissant que la copie sera correcte,
// meme si les zones se chevauchent.
void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t			i;

	if (src == 0 && dest == 0)
		return (NULL);
	i = 0;
	if (dest < src)
	{
		while (i < n)
		{
			((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
			i++;
		}
	}
	if (dest > src)
	{
		while (n > 0)
		{
			n--;
			((unsigned char *)dest)[n] = ((unsigned char *)src)[n];
		}
	}
	return (dest);
}
/*
int     main(void)
{
	char dest[] = " ";
	const char src[] = "Secondstring";
	memmove(dest, src, 2);
	printf("New arrays : %s\t%s\n", dest, src);
	ft_memmove(dest, src, 2);
	printf("New arrays : %s\t%s\n", dest, src);
   return 0;
}*/
