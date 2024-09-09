/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataher <ataher@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 13:41:49 by ataher            #+#    #+#             */
/*   Updated: 2024/09/09 10:59:42 by ataher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "libftprintf.h"
# include <stdarg.h>
# include <stdio.h>
/*
Allowed:
malloc, free, write,
va_start, va_arg, va_copy, va_end
*/
size_t	ft_strlen(char const *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	ft_putchar_fd(char c, int fd)
{
	return (write(fd, &c, 1))
}

int	ft_putstr_fd(char *s, int fd)
{
	return (write(fd, s, ft_strlen(s)));
}

int	ft_putnbr_fd(int n, int fd)
{
	int count;

	count = 0;
	if (n == -2147483648)
		return (ft_putstr_fd("-2147483648", fd));
	if (n < 0)
	{
		if (ft_putchar_fd('-', fd) == -1)
			return (-1);
		count++;
		n = -n;
	}
	if (n > 9)
	{
		if ((count += ft_putnbr_fd(n / 10, fd)) == -1)
			return (-1);
	}
	if (ft_putchar_fd(n % 10 + '0', fd) == -1)
		return (-1);
	count++;
	return (count);
}

static	int	ft_putaddress_fd(void *address, int fd)
{
	unsigned long addr = (unsigned long)address;

	char buffer[20];
	char *hex_chars = "0123456789abcdef";
	int i = sizeof(buffer) - 1;

	buffer[i--] = '\n';

	while (addr > 0)
	{
		buffer[i--] = hex_chars[addr % 16];
		addr /= 16;
	}
	buffer[i--] = 'x';
	buffer[i] = '0';

	return (write(fd, &buffer[i], sizeof(buffer) - i));
}

int	ft_printf(const char *format, ...)
{
	va_list	inputs;
	va_start(inputs, format);

	int i = 0;
	int count = 0;
	while(format[i])
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == 'd')
			{
				int len = ft_putnbr_fd(va_arg(inputs, int), 1);
				if (len == -1)
					return count;
				count += len;
			}
			if (format[i] == 's')
			{
				int len = ft_putstr_fd(va_arg(inputs, char *), 1);
				if (len == -1)
					return count;
				count += len;
			}
			if (format[i] == 'c')
			{
				if (ft_putchar_fd(va_arg(inputs, int), 1) == -1)
					return count;
				count += 1;
			}
			if (format[i] == 'p')
			{
				int len = ft_putaddress_fd((void *)va_arg(inputs, void *), 1);
				if (len == -1)
					return count;
				count += len;
			}


			if (format[i] == '%')
			{
				if (ft_putchar_fd('%', 1) == -1)
					return count;
				count += 1;
			}
		}
		else
		{
			if (ft_putchar_fd(format[i], 1) == -1)
				return count;
			count += 1;
		}
		i++;
	}
	va_end(inputs);
	return (count);
}


int main() {
	int a = 10;
	ft_putchar_fd('\n', 1);
	ft_putchar_fd('\n', 1);
	ft_printf("%d  %d %d %c--->\n %s 100%%  %p", 234, 23, 11, 'a',"asdfasdf", (void *)&a);

	printf("%p\n\n\n", (void *)&a);
}


/*


c DONE
s DONE
p DONE
d DONE
% DONE
i -
u -
x -
X -


*/



