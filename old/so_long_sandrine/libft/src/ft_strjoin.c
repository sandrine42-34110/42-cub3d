/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sapupier <sapupier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 07:51:29 by sapupier          #+#    #+#             */
/*   Updated: 2024/11/19 10:04:57 by sapupier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Alloue avec malloc et retourne une nvelle chaine, result de concatenation
// de s1 et s2.
char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*dest;
	int		n;
	int		i;
	int		j;

	n = ft_strlen(s1) + ft_strlen(s2);
	i = 0;
	dest = (char *)malloc((n + 1) * sizeof(char));
	if (!dest)
		return (NULL);
	while (i < (int)ft_strlen(s1))
	{
		dest[i] = s1[i];
		i++;
	}
	j = 0;
	while (j < (int)ft_strlen(s2))
	{
		dest[i + j] = s2[j];
		j++;
	}
	dest[i + j] = '\0';
	return (dest);
}
/*
int	main(void)
{
	printf("%s\n", ft_strjoin("Bonjour", "Hello"));
}*/