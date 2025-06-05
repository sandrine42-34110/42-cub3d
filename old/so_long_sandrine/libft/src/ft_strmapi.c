/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sapupier <sapupier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 15:26:38 by sapupier          #+#    #+#             */
/*   Updated: 2024/11/18 14:49:12 by sapupier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Applique la fonction 'f' a chq caract de la chaine 's', passant son index
// comme 1er argument et le caract lui-meme comme 2e argument.
// Une nvelle chaine de caract est cree avec malloc, resultant des appli
//successives de 'f')
//La fonction f doit retourner un caractère transformé. Le résultat de strmapi 
// est une nouvelle chaîne de caractères où chaque caractère est transformé 
// selon la fonction f.
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*str;

	i = 0;
	if (!s)
		return (NULL);
	str = (char *)(malloc((ft_strlen(s) + 1) * sizeof(char)));
	if (str == NULL)
		return (NULL);
	while (s[i] != '\0')
	{
		str[i] = f(i, s[i]);
		i++;
	}
	str[i] = '\0';
	return (str);
}

// char f(unsigned int i, char c)
// {
//     if (i % 2 == 0) {
//         return ft_toupper(c);  // Met en majuscule si l'indice est pair
//     }
//     return (c);  // Sinon, laisse le caractère tel quel
// }

// int	main(void)
// {
// 	char *result = ft_strmapi("Bonjour", f);
// 		printf("%s", result);
// 	free (result);
// 	return (0);
// }