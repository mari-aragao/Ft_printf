/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maragao <maragao@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 14:22:40 by maragao           #+#    #+#             */
/*   Updated: 2022/06/23 17:46:46 by maragao          ###   ########.rio      */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	count_nbr(int n)
{
	int len;
	
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
