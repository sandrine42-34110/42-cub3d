/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sapupier <sapupier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 08:51:46 by sapupier          #+#    #+#             */
/*   Updated: 2024/11/13 14:00:10 by sapupier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// Permet de rechercher la derniere occurrence d un caract specifique c dans
// une chaine de caractere
char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = ft_strlen(s);
	while (i >= 0)
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i--;
	}
	if ((char)c == '\0')
		return ((char *)&s[i]);
	return (NULL);
}
/*
#include <unistd.h>
#include <stdio.h>
#include <string.h>	
int	main(void)
{
	printf("%s\n", ft_strrchr("Bonjour", 'o'));
	printf("%s\n", strrchr("Bonjour", 'o'));
}*/
