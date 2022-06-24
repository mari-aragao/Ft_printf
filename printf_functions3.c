/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_functions3.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maragao <maragao@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 15:14:18 by maragao           #+#    #+#             */
/*   Updated: 2022/06/24 15:33:39 by maragao          ###   ########.rio      */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	count_hexa_long(unsigned long n)
{
	int	count;

	count = 0;
	while (n > 0)
	{
		n /= 16;
		count ++;
	}
	return (count);
}

int	ft_hexa_long(unsigned long n, char *base)
{
	int	res;
	int	count;

	if (!n)
		return (write(1, "0", 1));
	res = 0;
	count = count_hexa_long(n);
	if (n > 15)
		ft_hexa_long(n / 16, base);
	res = n % 16;
	write (1, &base[res], 1);
	return (count);
}

int	count_hexa(unsigned int n)
{
	int	count;

	count = 0;
	while (n > 0)
	{
		n /= 16;
		count ++;
	}
	return (count);
}

int	ft_hexa(unsigned int n, char *base)
{
	int	res;
	int	count;

	if (!n)
		return (write(1, "0", 1));
	res = 0;
	count = count_hexa(n);
	if (n > 15)
		ft_hexa(n / 16, base);
	res = n % 16;
	write (1, &base[res], 1);
	return (count);
}
