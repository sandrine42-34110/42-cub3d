/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sapupier <sapupier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 13:07:33 by sapupier          #+#    #+#             */
/*   Updated: 2024/11/13 07:59:02 by sapupier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// Allouer de la memoire (comme malloc)
// Verifier si l allocation a echoue (NULL)
// Utilisation de memset pour initialiser memoire a 0
void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	total_size;
	void	*ptr;

	total_size = (nmemb * size);
	if (nmemb * size != total_size)
		return (NULL);
	ptr = malloc(total_size);
	if (ptr == NULL)
		return (NULL);
	ft_memset (ptr, 0, total_size);
	return (ptr);
	return (ptr);
}
/*
#include <stdio.h>
#include <stdlib.h>

int main() 
{

    char    *str;

    str = ft_calloc(10, sizeof(char));
    int i;
    i = 0;
    while (i < 10)
    {
        if (str[i] == '\0')
            printf("0");
        else
            printf("%c", str[i]);
        i++;
    }
    size_t n = 5;  // Nombre d'éléments
    int *arr;

    // Utilisation de ft_calloc pour allouer un tableau de 5 entiers
    arr = (int*)ft_calloc(n, sizeof(int));

    // Vérification de l'allocation
    if (arr == NULL) {
        printf("Erreur d'allocation mémoire\n");
        return 1;  // Retourner 1 en cas d'erreur d'allocation
    }

    // Affichage des valeurs du tableau (devraient toutes être 0)
    printf("Valeurs après ft_calloc :\n");
    for (size_t i = 0; i < n; i++) {
        printf("arr[%zu] = %d\n", i, arr[i]);
    }

    // Libération de la mémoire allouée
    free(arr);

    free(str);
    return 0;
}*/
