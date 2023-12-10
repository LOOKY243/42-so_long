/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 16:53:27 by gmarre            #+#    #+#             */
/*   Updated: 2023/11/15 18:42:47 by gmarre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../so_long.h"

int	ft_which_printf(const char format, va_list args)
{
	int	bytes;

	bytes = 0;
	if (format == 'c')
		bytes = ft_putchar(va_arg(args, int));
	else if (format == '%')
		bytes = ft_putchar('%');
	else if (format == 'p')
		bytes = ft_void_sixteen(va_arg(args, unsigned long));
	else if (format == 'd' || format == 'i')
		bytes = ft_putnbr(va_arg(args, int));
	else if (format == 's')
		bytes = ft_putstr(va_arg(args, char *));
	else if (format == 'u')
		bytes = ft_putunsigned(va_arg(args, unsigned int));
	else if (format == 'x' || format == 'X')
		bytes = ft_base_sixteen((char)format, va_arg(args, unsigned int));
	return (bytes);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		bytes;
	int		i;

	i = 0;
	bytes = 0;
	va_start(args, format);
	if (format == NULL)
	{
		return (write(1, "-1", 1));
	}
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			bytes += ft_which_printf(format[i], args);
		}
		else
			bytes += write(1, &format[i], 1);
		i++;
	}
	va_end(args);
	return (bytes);
}
