/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cikuntay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 16:52:17 by cikuntay          #+#    #+#             */
/*   Updated: 2025/10/28 14:58:26 by cikuntay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

int	ft_putstr(char *s)
{
	if (s == NULL)
		return (write(1, "(null)", 6));
	return (write(1, s, ft_strlen(s)));
}

int	process_specifier(char flag, va_list ap)
{
	if (flag == 'd' || flag == 'i')
		return (ft_putnbr(va_arg(ap, int)));
	else if (flag == 'c')
		return (ft_putchar(va_arg(ap, int)));
	else if (flag == 'x')
		return (ft_puthex(va_arg(ap, unsigned int), 'x'));
	else if (flag == 'X')
		return (ft_puthex(va_arg(ap, unsigned int), 'X'));
	else if (flag == 'p')
		return (ft_putptr(va_arg(ap, void *)));
	else if (flag == 'u')
		return (print_u(va_arg(ap, unsigned int)));
	else if (flag == '%')
		return (ft_putchar('%'));
	return (-1);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		count;
	int		temp;

	va_start(ap, format);
	count = 0;
	while (*format)
	{
		temp = 0;
		if (*format == '%')
		{
			format++;
			temp = process_specifier(*format, ap);
			if (temp == -1)
				return (-1);
			count += temp;
		}
		else
			count += ft_putchar(*format);
		format++;
	}
	va_end(ap);
	return (count);
}
