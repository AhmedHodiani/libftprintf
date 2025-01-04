/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataher <ataher@student.42amman.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 13:41:49 by ataher            #+#    #+#             */
/*   Updated: 2025/01/04 05:48:54 by ataher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	hp_printf(int fd, char format, va_list inputs)
{
	if (format == 'd' || format == 'i')
		return (ft_putnbr_fd(va_arg(inputs, int), fd));
	if (format == 's')
		return (ft_putstr_fd(va_arg(inputs, char *), fd));
	if (format == 'c')
		return (hp_putchar_fd(va_arg(inputs, int), fd));
	if (format == 'p')
		return (ft_putaddress_fd((void *)va_arg(inputs, void *), fd));
	if (format == 'x' || format == 'X')
		return (ft_puthex_fd(va_arg(inputs, unsigned int), format, fd));
	if (format == 'u')
		return (ft_putunsigned_fd(va_arg(inputs, unsigned int), fd));
	if (format == '%')
		return (hp_putchar_fd('%', fd));
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	inputs;
	int		i;
	int		count;

	if (stdout->_flags & 8)
		return (-1);
	va_start(inputs, format);
	i = 0;
	count = 0;
	while (format[i])
	{
		if (format[i] == '%')
			count += hp_printf(1, format[++i], inputs);
		else
			count += hp_putchar_fd(format[i], 1);
		i++;
	}
	va_end(inputs);
	return (count);
}

int	ft_dprintf(int fd, const char *format, ...)
{
	va_list	inputs;
	int		i;
	int		count;

	if (stdout->_flags & 8)
		return (-1);
	va_start(inputs, format);
	i = 0;
	count = 0;
	while (format[i])
	{
		if (format[i] == '%')
			count += hp_printf(fd, format[++i], inputs);
		else
			count += hp_putchar_fd(format[i], fd);
		i++;
	}
	va_end(inputs);
	return (count);
}

int ft_color_printf(char *color, const char *format, ...)
{
	va_list	inputs;
	int		i;
	int		count;

	if (stdout->_flags & 8)
		return (-1);
	va_start(inputs, format);
	i = 0;
	count = 0;
	ft_printf("%s", color);
	while (format[i])
	{
		if (format[i] == '%')
			count += hp_printf(1, format[++i], inputs);
		else
			count += hp_putchar_fd(format[i], 1);
		i++;
	}
	ft_printf("%s", RESET);
	va_end(inputs);
	return (count);
}
