/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_hex_ptr_pf.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sapupier <sapupier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 15:43:08 by sapupier          #+#    #+#             */
/*   Updated: 2025/02/13 10:17:48 by sapupier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// to print numbers in hexadecimal format
int	ft_putnbr_hex_ptr_pf(unsigned long n, char *base)
{
	int		i;

	i = 0;
	if (n >= 16)
	{
		i += ft_putnbr_hex_ptr_pf(n / 16, base);
	}
	i += ft_putchar_pf(base[n % 16]);
	return (i);
}
