/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_help.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwalad <zwalad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 19:04:33 by zwalad            #+#    #+#             */
/*   Updated: 2021/11/30 17:06:15 by zwalad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"ft_printf.h"

static int	ft_norm1(int nbr, int size)
{
	if (nbr < 0)
	{
		nbr *= -1;
		size++;
	}
	if (nbr == 0)
		return (1);
	while (nbr)
	{
		nbr /= 10;
		size++;
	}
	return (size);
}

int	ft_putnbr(int nbr)
{
	int	size;
	int	nb;

	if (nbr == -2147483648)
	{
		ft_putstr("-2147483648");
		return (11);
	}
	nb = nbr;
	if (nbr < 0)
	{
		nbr *= -1;
		ft_putchar('-');
	}
	if (nbr <= 9)
		ft_putchar(nbr + '0');
	if (nbr > 9)
	{
		ft_putnbr(nbr / 10);
		ft_putnbr(nbr % 10);
	}
	size = ft_norm1(nb, 0);
	return (size);
}

int	ft_hexa(unsigned int nb, char *s)
{
	int	size;

	if (nb < 16)
		ft_putchar(s[nb]);
	else if (nb >= 16)
	{
		ft_hexa(nb / 16, s);
		ft_hexa(nb % 16, s);
	}
	size = 0;
	if (nb == 0)
		return (1);
	while (nb)
	{
		nb /= 16;
		size++;
	}
	return (size);
}

int	ft_pupo(unsigned long long nb, char *s)
{
	int	size;

	if (nb < 16)
		ft_putchar(s[nb]);
	if (nb >= 16)
	{
		ft_pupo(nb / 16, s);
		ft_pupo(nb % 16, s);
	}
	size = 0;
	if (nb == 0)
		return (1);
	while (nb)
	{
		nb /= 16;
		size++;
	}
	return (size);
}
