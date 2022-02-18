/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_help2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwalad <zwalad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 20:55:15 by zwalad            #+#    #+#             */
/*   Updated: 2021/11/30 17:06:23 by zwalad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"ft_printf.h"

int	ft_putstr(char *s)
{
	int	i;

	i = 0;
	if (!s)
	{
		write(1, "(null)", 6);
		return (6);
	}
	else
	{
		while (s[i])
		{
			write(1, &s[i], 1);
			i++;
		}
	}
	return (i);
}

static int	ft_norm(unsigned int nbr, int size)
{
	if (nbr == 0)
		return (1);
	while (nbr)
	{
		nbr /= 10;
		size++;
	}
	return (size);
}

int	ft_putuns(unsigned int nbr)
{
	int	size;

	size = 0;
	if (nbr <= 9)
		ft_putchar(nbr + '0');
	if (nbr > 9)
	{
		ft_putuns(nbr / 10);
		ft_putuns(nbr % 10);
	}
	size = ft_norm(nbr, size);
	return (size);
}

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}
