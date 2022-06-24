/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_functions2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maragao <maragao@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 15:12:52 by maragao           #+#    #+#             */
/*   Updated: 2022/06/24 15:32:34 by maragao          ###   ########.rio      */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	count_nbr(int n)
{
	int	len;

	len = 0;
	if (n < 0)
	{
		n = -n;
		len++;
	}
	while (n > 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

int	ft_putnbr_fd(int n, int fd)
{
	char	res;
	int		len;

	len = count_nbr(n);
	res = 0;
	if (n == -2147483648)
	{
		ft_putstr_fd ("-2147483648", fd);
		return (11);
	}
	if (n < 0)
	{
		write (fd, "-", 1);
		n = n * -1;
	}
	if (n > 9)
		ft_putnbr_fd(n / 10, fd);
	res = n % 10 + '0';
	write (fd, &res, 1);
	if (n == 0)
		return (1);
	return (len);
}

int	count_nbr_u(unsigned int n)
{
	int	len;

	len = 0;
	while (n > 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

int	ft_putnbr_u(unsigned int n, int fd)
{
	char	res;
	int		len;

	len = count_nbr_u(n);
	res = 0;
	if (n > 9)
		ft_putnbr_u(n / 10, fd);
	res = n % 10 + '0';
	write (fd, &res, 1);
	if (n == 0)
		return (1);
	return (len);
}
