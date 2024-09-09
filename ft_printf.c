/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataher <ataher@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 13:41:49 by ataher            #+#    #+#             */
/*   Updated: 2024/09/09 10:34:04 by ataher           ###   ########.fr       */
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

void	ft_putchar_fd(char c, int fd)
{
	write (fd, &c, 1);
}

void	ft_putstr_fd(char *s, int fd)
{
	write(fd, s, ft_strlen(s));
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
	{
		ft_putstr_fd("-2147483648", fd);
		return ;
	}
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		n = -n;
	}
	if (n > 9)
		ft_putnbr_fd(n / 10, fd);
	ft_putchar_fd(n % 10 + '0', fd);
}

static	void	ft_putaddress_fd(void *address, int fd) {
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

    write(fd, &buffer[i], sizeof(buffer) - i);
}

void	ft_printf(const char *format, ...)
{
	ft_putchar_fd('\n', 1);
	ft_putchar_fd('\n', 1);

	va_list	inputs;
	va_start(inputs, format);

	int i = 0;
	while(format[i])
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == 'd')
				ft_putnbr_fd(va_arg(inputs, int), 1);
			if (format[i] == 's')
				ft_putstr_fd(va_arg(inputs, char *), 1);
			if (format[i] == 'c')
				ft_putchar_fd(va_arg(inputs, int), 1);
			if (format[i] == 'p')
				ft_putaddress_fd((void *)va_arg(inputs, void *), 1);


			if (format[i] == '%')
				ft_putchar_fd('%', 1);
		}
		else
			ft_putchar_fd(format[i], 1);
		i++;
	}

	ft_putchar_fd('\n', 1);
	ft_putchar_fd('\n', 1);
	va_end(inputs);
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



