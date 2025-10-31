/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cikuntay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 16:24:57 by cikuntay          #+#    #+#             */
/*   Updated: 2025/10/28 16:50:07 by cikuntay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_putnbr(int num)
{
	int		count;
	char	number;

	count = 0;
	if (num == -2147483648)
		return (write(1, "-2147483648", 11));
	if (num < 0)
	{
		count += write(1, "-", 1);
		num *= -1;
	}
	if (num >= 10)
		count += ft_putnbr(num / 10);
	number = (num % 10) + '0';
	count += write(1, &number, 1);
	return (count);
}

int	print_u(unsigned int num)
{
	int	written;

	written = 0;
	if (num >= 10)
		written += print_u(num / 10);
	written += ft_putchar((num % 10) + '0');
	return (written);
}

int	ft_puthex(unsigned int n, char format)
{
	char	*hex;
	int		count;

	count = 0;
	if (format == 'x')
		hex = "0123456789abcdef";
	else
		hex = "0123456789ABCDEF";
	if (n >= 16)
		count += ft_puthex(n / 16, format);
	count += write(1, &hex[n % 16], 1);
	return (count);
}

int	ft_putptr(void *p)
{
	unsigned long	ptr;
	char			*hex;
	int				count;

	ptr = (unsigned long)p;
	hex = "0123456789abcdef";
	count = 0;
	if (!p)
		return (write(1, "(nil)", 5));
	count += write(1, "0x", 2);
	if (ptr >= 16)
		count += ft_putptr((void *)(ptr / 16));
	count += write(1, &hex[ptr % 16], 1);
	return (count);
}
