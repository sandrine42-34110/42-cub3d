/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_pf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sapupier <sapupier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 15:43:08 by sapupier          #+#    #+#             */
/*   Updated: 2025/02/13 10:17:42 by sapupier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbr_pf(int n)
{
	int	i;

	i = 0;
	if (n == -2147483648)
	{
		i = write(1, "-2147483648", 11);
		return (i);
	}
	if (n < 0)
	{
		i += write(1, "-", 1);
		n = -n;
	}
	if (n > 9)
	{
		i += ft_putnbr_pf((n / 10));
	}
	i += ft_putchar_pf(((n % 10) + '0'));
	return (i);
}
/*
int main (void)
{
	int result;

    result = ft_putnbr_pf(-648);
    printf("\nNombre de caractères imprimés : %d\n", result);
    return (0);
}*/