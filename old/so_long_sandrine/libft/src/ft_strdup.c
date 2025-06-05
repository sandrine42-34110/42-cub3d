/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sapupier <sapupier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 13:07:33 by sapupier          #+#    #+#             */
/*   Updated: 2024/11/13 08:08:33 by sapupier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Sert a dupliquer une chaine de caractere, dans un nvel emplact memoire.
// Entrée : Une chaîne de caractères (par exemple, "bonjour").
// Sortie : Une nvelle chaîne allouée dynamiquement, qui contient une copie 
// 			exacte de la chaîne d'entrée.
// Mémoire : La nouvelle chaîne est allouée avec malloc.
// Il est donc important de libérer la mémoire allouée avec free() lorsque la 
// chaîne n'est plus nécessaire.
char	*ft_strdup(const char *s)
{
	char	*dest;
	int		i;

	i = 0;
	dest = malloc(ft_strlen(s) + 1);
	if (!dest)
		return (NULL);
	while (s[i])
	{
		dest[i] = s[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
/*
#include <stdio.h>
#include <stdlib.h>

int main() 
{
	char tab[] = "Salut";
	printf("tab = %s\n", tab);
	printf("chaine copiee avec strdup = %s\n", ft_strdup(tab));
	return EXIT_SUCCESS;
}*/