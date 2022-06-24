/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maragao <maragao@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 15:35:09 by maragao           #+#    #+#             */
/*   Updated: 2022/06/24 15:27:25 by maragao          ###   ########.rio      */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_options(char c, va_list args)
{
	int	i;

	i = 0;
	if (c == 'c')
		i = ft_putchar_fd(va_arg(args, int), 1);
	if (c == 's')
		i = ft_putstr_fd(va_arg(args, char *), 1);
	if (c == 'p')
	{
		write(1, "0x", 2);
		i = ft_hexa_long(va_arg(args, unsigned long), "0123456789abcdef") + 2;
	}
	if (c == 'd' || c == 'i')
		i = ft_putnbr_fd(va_arg(args, int), 1);
	if (c == 'u')
		i = ft_putnbr_u(va_arg(args, unsigned int), 1);
	if (c == 'x')
		i = ft_hexa(va_arg(args, unsigned int), "0123456789abcdef");
	if (c == 'X')
		i = ft_hexa(va_arg(args, unsigned int), "0123456789ABCDEF");
	if (c == '%')
		i = ft_putchar_fd('%', 1);
	return (i);
}

int	ft_printf(const char *s, ...)
{
	va_list	args;
	int		i;
	int		len;

	va_start(args, s);
	i = 0;
	len = 0;
	while (s[i])
	{
		if (s[i] == '%' && ft_strchr("cspdiuxX%", s[i + 1]))
		{
			len += ft_printf_options(s[i + 1], args);
			i++;
		}
		else
		{
			ft_putchar_fd(s[i], 1);
			len++;
		}
		i++;
	}
	va_end(args);
	return (len);
}
