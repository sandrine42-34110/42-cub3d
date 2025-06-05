/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sapupier <sapupier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 12:58:04 by sapupier          #+#    #+#             */
/*   Updated: 2024/11/13 15:24:01 by sapupier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Alloue avec malloc et retourne une copie de la chaine s1, ss les caracteres
// specifies dans set au debut et a la fin de la chaine de caract
char	*ft_strtrim(char const *s1, char const *set)
{
	char	*dest;
	int		i;
	int		end;

	i = 0;
	end = ft_strlen(s1);
	dest = 0;
	if (!s1)
		return (NULL);
	while (ft_strchr(set, s1[i]))
		i++;
	while (ft_strchr(set, s1[end]))
		end--;
	end = end + 1 - i;
	dest = ft_substr(s1, i, end);
	return (dest);
}
/*
int	main(void)
{
	printf("%s\n", ft_strtrim("Bonjour", "Bro"));
}*/