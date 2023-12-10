/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_funct.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 16:37:38 by gmarre            #+#    #+#             */
/*   Updated: 2023/11/15 11:10:50 by gmarre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_putnbr(int n)
{
	int		len;
	int		neg;

	len = 0;
	neg = 0;
	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	if (n < 0)
	{
		n *= -1;
		ft_putchar('-');
		neg = 1;
	}
	if (n >= 10)
		len = ft_putnbr(n / 10);
	len++;
	ft_putchar(n % 10 + '0');
	if (neg)
		return (len + 1);
	return (len);
}

int	ft_putunsigned(unsigned int n)
{
	int	len;

	len = 0;
	if (n >= 10)
		len = ft_putunsigned(n / 10);
	len++;
	ft_putchar((n % 10) + '0');
	return (len);
}

int	ft_base_sixteen(char arg, unsigned int n)
{
	char	*base;
	int		len;

	len = 0;
	if (arg == 'x')
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";
	if (n >= 16)
		len = ft_base_sixteen(arg, n / 16);
	len++;
	write(1, &base[n % 16], 1);
	return (len);
}

int	ft_void_sixteen(unsigned long nb)
{
	char	*ptr;
	int		len;

	ptr = "0123456789abcdef";
	len = 0;
	if (!nb)
	{
		write (1, "(nil)", 5);
		return (5);
	}
	if (nb >= 16)
		len = ft_void_sixteen(nb / 16);
	if (len == 0)
		len += write(1, "0x", 2);
	len++;
	write(1, &ptr[nb % 16], 1);
	return (len);
}
