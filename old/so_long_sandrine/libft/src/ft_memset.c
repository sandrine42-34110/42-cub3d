/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sapupier <sapupier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 15:58:32 by sapupier          #+#    #+#             */
/*   Updated: 2024/11/19 09:07:29 by sapupier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// Cette fonction permet de remplir une zone memoire, identifiee par son
// adresse et par sa taille, avec une valeur precise. ptr = s permet de 
// transformer le void en c.
void	*ft_memset(void *s, int c, size_t n)
{
	char	*ptr;

	ptr = s;
	while (n > 0)
	{
		*ptr = c;
		ptr++;
		n--;
	}
	return (s);
}
/*
int	main(void)
{
	char	tab[] = "Bonjour";
//	memset(tab, 'a', 2);
	printf("%s\n", tab);
	ft_memset(tab, 'a', 2);
	printf("%s", tab);
}*/
