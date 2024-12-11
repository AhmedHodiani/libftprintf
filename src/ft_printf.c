/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataher <ataher@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 13:41:49 by ataher            #+#    #+#             */
/*   Updated: 2024/12/11 16:15:16 by ataher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	hp_printf(char format, va_list inputs)
{
	if (format == 'd' || format == 'i')
		return (ft_putnbr_fd(va_arg(inputs, int), 1));
	if (format == 's')
		return (ft_putstr_fd(va_arg(inputs, char *), 1));
	if (format == 'c')
		return (hp_putchar_fd(va_arg(inputs, int), 1));
	if (format == 'p')
		return (ft_putaddress_fd((void *)va_arg(inputs, void *), 1));
	if (format == 'x' || format == 'X')
		return (ft_puthex_fd(va_arg(inputs, unsigned int), format, 1));
	if (format == 'u')
		return (ft_putunsigned_fd(va_arg(inputs, unsigned int), 1));
	if (format == '%')
		return (hp_putchar_fd('%', 1));
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
			count += hp_printf(format[++i], inputs);
		else
			count += hp_putchar_fd(format[i], 1);
		i++;
	}
	va_end(inputs);
	return (count);
}

void	ft_printf_strings(char **strings)
{
	int	i;

	i = 0;
	while (strings[i])
	{
		ft_printf("%s\n", strings[i]);
		i++;
	}
}
// int main() {
// 	int a = 0;
// 	hp_putchar_fd('\n', 1);
// 	hp_putchar_fd('\n', 1);

// 	ft_printf("%p", NULL);
// 	printf("\n\n\n%p\n\n\n", NULL);
// }
