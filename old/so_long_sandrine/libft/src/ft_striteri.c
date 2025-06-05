/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sapupier <sapupier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 15:26:38 by sapupier          #+#    #+#             */
/*   Updated: 2024/11/18 14:44:33 by sapupier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Applique la fonction 'f' a chq caract de la chaine transmise comme argument,
// et en passant son index comme 1er argument.  Chq caract est transmis par 
// adresse a 'f' afin d etre modifie si necessaire.
void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	i = 0;
	if (s)
	{
		while (s[i] != '\0')
		{
			(*f)(i, s + i);
			i++;
		}
	}
	s[i] = '\0';
}

// void f(unsigned int, char *c)
// {
// 	*c = ft_toupper((unsigned char)*c);  // Met en majuscule le caractere
// }

// int	main(void)
// {
// 	char str[] = "bonjour";
// 	ft_striteri(str, f);
// 	printf("%s\n", str);
// 	return (0);
// }