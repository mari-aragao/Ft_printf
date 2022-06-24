/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_functions1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maragao <maragao@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 15:07:11 by maragao           #+#    #+#             */
/*   Updated: 2022/06/24 15:31:38 by maragao          ###   ########.rio      */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar_fd(char c, int fd)
{
	return (write (fd, &c, 1));
}

int	ft_putstr_fd(char *s, int fd)
{
	int	i;
	int	len;

	i = 0;
	if (!s)
		return (write(1, "(null)", 6));
	len = 0;
	while (s[len])
		len++;
	while (s[i])
		write(fd, &s[i++], 1);
	return (len);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != 0)
	{
		if (s[i] == (char) c)
			return ((char *)(s + i));
		i++;
	}
	if (s[i] == (char) c)
		return ((char *)(s + i));
	return (0);
}
