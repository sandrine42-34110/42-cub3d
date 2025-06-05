/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sapupier <sapupier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 13:07:33 by sapupier          #+#    #+#             */
/*   Updated: 2024/11/13 08:05:14 by sapupier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// permet de rechercher la première occurrence d'une sous-chaîne dans une 
//chaîne principale, mais en limitant la recherche à un nombre donné de 
//caractères (indiqué par un paramètre n). 
// Si la chaine little est vide, on retourne big
// parcours jusqu a n ou la fin de big
// si on a trouve toute la chaine little
char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (*little == '\0')
		return ((char *)big);
	while (big[i] && i < len)
	{
		j = 0;
		while (big[i + j] == little[j] && (i + j) < len)
		{
			j++;
			if (little[j] == '\0')
				return ((char *)(big + i));
		}
		i++;
	}
	return (0);
}
/*
#include <unistd.h>
#include <stdio.h>
#include <string.h>
int main() {
    const char *big = "Hello, world!";
    const char *little = "world";
    size_t len = 2;  // Recherche sur toute la chaîne

    char *result = ft_strnstr(big, little, len);
    if (result) {
        printf("Trouvé: %s\n", result);
    } else {
        printf("Non trouvé\n");
    }

    return 0;
}*/