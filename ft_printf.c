/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwalad <zwalad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 19:04:09 by zwalad            #+#    #+#             */
/*   Updated: 2021/11/30 17:06:29 by zwalad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include    "ft_printf.h"

static int	ft_cdxu(char c, va_list args)
{
	int	size;

	size = 0;
	if (c == 'c')
		size = ft_putchar(va_arg(args, int));
	else if (c == '%')
		size = ft_putchar(c);
	else if (c == 'd' || c == 'i')
		size = ft_putnbr(va_arg(args, int));
	else if (c == 's')
		size = ft_putstr(va_arg(args, char *));
	else if (c == 'u')
		size = ft_putuns(va_arg(args, unsigned int));
	else if (c == 'x')
		size = ft_hexa(va_arg(args, unsigned int), "0123456789abcdef");
	else if (c == 'X')
		size = ft_hexa(va_arg(args, unsigned int), "0123456789ABCDEF");
	else if (c == 'p')
	{
		size = ft_putstr("0x");
		size += ft_pupo(va_arg(args, unsigned long long), "0123456789abcdef");
	}
	return (size);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		size;
	int		i;

	size = 0;
	i = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			size += ft_cdxu(str[i], args);
			i++;
		}
		else
		{
			ft_putchar(str[i]);
			i++;
			size++;
		}
	}
	va_end(args);
	return (size);
}
