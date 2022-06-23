/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maragao <maragao@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 14:22:40 by maragao           #+#    #+#             */
/*   Updated: 2022/06/23 17:51:47 by maragao          ###   ########.rio      */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	count_nbr_u(unsigned int n)
{
	int len;
	
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
