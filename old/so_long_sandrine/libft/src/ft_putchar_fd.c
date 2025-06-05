/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sapupier <sapupier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 14:51:41 by sapupier          #+#    #+#             */
/*   Updated: 2024/11/18 15:22:08 by sapupier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Ecrit le caractere 'c' sur le descripteur de fichier donne (fd)
void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

// int main (void)
// {
// 	ft_putchar_fd('B', 1);
// 	return (0);
// }