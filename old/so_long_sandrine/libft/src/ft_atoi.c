/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sapupier <sapupier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 13:07:33 by sapupier          #+#    #+#             */
/*   Updated: 2024/11/19 08:26:08 by sapupier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Prend en argument une chaine de caracteres et renvoie l entier correspondant
int	ft_atoi(const char *nptr)
{
	int	i;
	int	result;
	int	n;
	int	sign;

	i = 0;
	result = 0;
	n = 1;
	sign = 1;
	while ((nptr[i] >= '\t' && nptr[i] <= '\r') || nptr[i] == ' ')
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
		{
			n = -n;
			sign = -sign;
		}
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
		result = result * 10 + (nptr[i++] - '0');
	return (result * sign);
}
/*
#include <stdlib.h>
#include <stdio.h>
int     main(void)
{
        printf("%d \n", ft_atoi("1234"));
        printf("%d \n", atoi("1234"));
        printf("%d \n", ft_atoi("   \r 45352542"));
		printf("%d \n", atoi("   \r 45352542"));
        printf("%d \n", ft_atoi("- 1 2 3 4"));
		printf("%d \n", atoi("- 1 2 3 4"));
        printf("%d \n", ft_atoi("\v2147483647"));
		printf("%d \n", atoi("\v2147483647"));
        printf("%d \n", ft_atoi("-100"));
		printf("%d \n", atoi("-100"));
        printf("%d \n", ft_atoi("0"));
		printf("%d \n", atoi("0"));
		printf("%d \n", ft_atoi("\t2147483647"));
		printf("%d \n", atoi("\t2147483647"));
		printf("%d \n", ft_atoi("at2147483647"));
		printf("%d \n", atoi("at2147483647"));
		return (0);
}*/
