/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sapupier <sapupier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 09:22:06 by sapupier          #+#    #+#             */
/*   Updated: 2025/02/13 10:18:30 by sapupier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	convert(va_list args, char format)
{
	int	i;

	i = 0;
	if (format == 'c')
		i += ft_putchar_pf(va_arg(args, int));
	else if (format == 's')
		i += ft_putstr_pf(va_arg(args, char *));
	else if (format == 'd')
		i += ft_putnbr_pf(va_arg(args, int));
	else if (format == '%')
		i += write(1, "%", 1);
	else if (format == 'p')
		i += ft_putptr_pf(va_arg(args, unsigned long));
	else if (format == 'i')
		i += ft_putnbr_pf(va_arg(args, int));
	else if (format == 'u')
		i += ft_putnbr_u_pf(va_arg(args, unsigned int));
	else if (format == 'x')
		i += ft_putnbr_hex_pf(va_arg(args, unsigned int), "0123456789abcdef");
	else if (format == 'X')
		i += ft_putnbr_hex_pf(va_arg(args, unsigned int), "0123456789ABCDEF");
	return (i);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;

	i = 0;
	va_start(args, format);
	{
		while (*format)
		{
			if (*format == '%' && *(format + 1))
			{
				format ++;
				i += convert(args, *format);
			}
			else
			{
				ft_putchar_pf(*format);
				i++;
			}
			format++;
		}
	}
	va_end(args);
	return (i);
}
/*	int	main()
	{
	int	i = 0;
	char c = 'A';
    i = printf("Le caractère est : %c\n", c);
   	
	printf("\nNombre de caractères imprimés : %d\n", i);
	i = ft_printf("Le caractère est : %c\n", c);
	printf("\nNombre de caractères imprimés : %d\n", i);
	char *c = "BONJOUR";
    i = printf("La chaine de caractères est : %s\n", c);
   	printf("\nNombre de caractères imprimés : %d\n", i);
	i = ft_printf("La chaine de caractères est : %s\n", c);
	printf("\nNombre de caractères imprimés : %d\n", i);	
	int c = 123;
    i = printf("Le nombre est : %d\n", c);
   	printf("\nNombre de caractères imprimés : %d\n", i);
	i = ft_printf("Le nombre est : %d\n", c);
	printf("\nNombre de caractères imprimés : %d\n", i);
	char c = '%';
    i = printf("Le caractere est : %c\n", c);
   	printf("\nNombre de caractères imprimés : %d\n", i);
	i = ft_printf("Le caractere est : %c\n", c);
	printf("\nNombre de caractères imprimés : %d\n", i);
	char *c = "BONJOUR";
    i = printf("L adresse de ce pointeur est : %p\n", c);
   	printf("\nNombre de caractères imprimés : %d\n", i);
	i = ft_printf("L adresse de ce pointeur est : %p\n", c);
	printf("\nNombre de caractères imprimés : %d\n", i);
	int c = -2147483648;
	i = printf("Le nombre est : %i\n", c);
	printf("\nNombre de caractères imprimés : %d\n", i);
	i = ft_printf("Le nombre est : %i\n", c);
	printf("\nNombre de caractères imprimés : %d\n", i);
	int c = -2147483648;
	i = printf("Le nombre est : %u\n", c);
	printf("\nNombre de caractères imprimés : %d\n", i);
	i = ft_printf("Le nombre est : %u\n", c);
	printf("\nNombre de caractères imprimés : %d\n", i);
	int c = 47;
	i = printf("Le nombre est : %x\n", c);
	printf("\nNombre de caractères imprimés : %d\n", i);
	i = ft_printf("Le nombre est : %x\n", c);
	printf("\nNombre de caractères imprimés : %d\n", i);
	c = -47;
	i = printf("Le nombre est : %X\n", c);
	printf("\nNombre de caractères imprimés : %d\n", i);
	i = ft_printf("Le nombre est : %X\n", c);
	printf("\nNombre de caractères imprimés : %d\n", i);
	return (0);
}*/
