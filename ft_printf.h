/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maragao <maragao@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 15:35:23 by maragao           #+#    #+#             */
/*   Updated: 2022/06/24 15:36:04 by maragao          ###   ########.rio      */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>

char	*ft_strchr(const char *s, int c);
int		ft_putchar_fd(char c, int fd);
int		ft_putstr_fd(char *s, int fd);
int		ft_putnbr_fd(int n, int fd);
int		ft_putnbr_u(unsigned int n, int fd);
int		ft_hexa(unsigned int n, char *base);
int		ft_printf(const char *s, ...);
int		ft_hexa_long(unsigned long n, char *base);

#endif
