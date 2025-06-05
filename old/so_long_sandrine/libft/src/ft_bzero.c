/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sapupier <sapupier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 12:20:51 by sapupier          #+#    #+#             */
/*   Updated: 2024/11/13 08:09:40 by sapupier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*ptr;

	ptr = s;
	while (n > 0)
	{
		*ptr = 0;
		ptr++;
		n--;
	}
}
/*
#include <strings.h>
#include <stdio.h>
int     main(void)
{
	char    tab[] = "Bonjour";
//	bzero(tab, 2);
        printf("%s\n", tab + 2);
	ft_bzero(tab, 2);
        printf("%s", tab + 2);
}*/
