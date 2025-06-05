/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sapupier <sapupier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 15:26:38 by sapupier          #+#    #+#             */
/*   Updated: 2024/11/14 07:27:08 by sapupier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_len(int n)
{
	int	len;

	len = 0;
	if (n <= 0)
	{
		len++;
	}
	while (n != 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

// Alloue avec malloc et retourne une de chaine de caract representant l entier
// 'n' recu en argument. Les nb negatifs doivent etre geres.
char	*ft_itoa(int n)
{
	char	*str;
	int		i;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	str = (char *)malloc((ft_len(n) + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	str[ft_len(n)] = '\0';
	i = ft_len(n) -1;
	if (n == 0)
	{
		str[0] = '0';
	}
	if (n < 0)
	{
		str[0] = '-';
		n = -n;
	}
	while (n != 0)
	{
		str[i--] = (n % 10) + 48;
		n = n / 10;
	}
	return (str);
}
/*
#include <stdio.h>
int	main(void)
{
 		int	n;
		n = -214748364;
		printf("%s\n", ft_itoa(n));
}*/