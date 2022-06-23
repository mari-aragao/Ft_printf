/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maragao <maragao@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 14:15:31 by maragao           #+#    #+#             */
/*   Updated: 2022/06/23 17:19:54 by maragao          ###   ########.rio      */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr_fd(char *s, int fd)
{
	int	i;
	int len;

	i = 0;
	if (!s)
		return (write(1, "(null)", 6));
	len = 0;
	while (s[len])
		len++;
	while (s[i])
		write(fd, &s[i++], 1);
	return ((int) len);
}
