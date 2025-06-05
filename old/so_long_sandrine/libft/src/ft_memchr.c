/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sapupier <sapupier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 07:39:06 by sapupier          #+#    #+#             */
/*   Updated: 2024/11/18 17:23:15 by sapupier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Parcours les 'n' premiers octets pointes par 's' et recherche la 1ere occur.
// dont la valeur est = a 'c'.
void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	ch;
	unsigned char	*t;

	i = 0;
	ch = (unsigned char)c;
	t = (unsigned char *)s;
	while (i < n)
	{
		if (t[i] == ch)
			return ((void *)(t + i));
		i++;
	}
	return (NULL);
}
/*int main() {
    const char buffer[] = "Hello, world!";
    
    // Recherche de 'o' dans les 10 premiers octets du buffer
    char *result = memchr(buffer, 'o', 10);
    
    if (result != NULL) {
        printf("Trouvé ! Le caractère 'o' est à l'adresse %p
		 et à la position %ld.\n", result, result - buffer);
    } else {
        printf("Le caractère 'o' n'a pas été trouvé.\n");
    }
    return 0;
}*/