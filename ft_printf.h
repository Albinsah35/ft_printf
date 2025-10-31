/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cikuntay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 14:48:51 by cikuntay          #+#    #+#             */
/*   Updated: 2025/10/31 15:51:00 by cikuntay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>

int		ft_printf(const char *format, ...);
int		process_specifier(char flag, va_list ap);

int		ft_putchar(char c);
int		ft_putstr(char *s);
int		ft_strlen(char *str);
int		ft_putnbr(int num);
int		print_u(unsigned int num);
int		ft_puthex(unsigned int n, char format);
int		ft_putptr(void *p);

#endif
