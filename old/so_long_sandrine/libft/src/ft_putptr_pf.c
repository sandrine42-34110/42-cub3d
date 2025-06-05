/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr_pf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sapupier <sapupier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 14:51:41 by sapupier          #+#    #+#             */
/*   Updated: 2025/02/13 10:17:27 by sapupier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Affiche l adresse d un pointeur en format hexadecimal, precedee de 0x.
// Gere le cas ou l adresse est NULL en affichant (nil).
int	ft_putptr_pf(unsigned long ptr)
{
	int	i;

	i = 0;
	if (ptr == 0)
		return (write(1, "(nil)", 5));
	i += write(1, "0x", 2);
	i += ft_putnbr_hex_ptr_pf(ptr, "0123456789abcdef");
	return (i);
}
