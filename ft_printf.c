/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataher <ataher@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 13:41:49 by ataher            #+#    #+#             */
/*   Updated: 2024/09/08 12:26:45 by ataher           ###   ########.fr       */
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

void print_address(void *ptr) {
    const char hex_digits[] = "0123456789abcdef";
    char buffer[2 + sizeof(void*) * 2 + 1];  // Buffer for "0x" + hex digits + null terminator
    unsigned char *addr = (unsigned char*)&ptr;
    int i;

    // Start with "0x"
    buffer[0] = '0';
    buffer[1] = 'x';

    // Convert the pointer address to hexadecimal
    for (i = sizeof(void*) - 1; i >= 0; i--) {
        buffer[2 + 2 * (sizeof(void*) - 1 - i)] = hex_digits[(addr[i] >> 4) & 0x0F];
        buffer[2 + 2 * (sizeof(void*) - 1 - i) + 1] = hex_digits[addr[i] & 0x0F];
    }

    // Null-terminate the string
    buffer[2 + 2 * sizeof(void*)] = '\0';

    // Write the formatted address string to standard output
    write(STDOUT_FILENO, buffer, 2 + 2 * sizeof(void*));
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

			// print address
			if (format[i] == 'p')
				print_address(va_arg(inputs, void *));



			if (format[i] == '%')
				ft_putchar_fd('%', 1);
		}
		else
			ft_putchar_fd(format[i], 1);
		i++;
	}

	// int a = va_arg(inputs, int);
	// int b = va_arg(inputs, int);

	// ft_putstr_fd((char *)format, 1);
	// ft_putchar_fd('\n', 1);

	// ft_putnbr_fd(a, 1);
	// ft_putnbr_fd(b, 1);



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

c
s
p ---------

d
i --------------
u ------------
x-----------
X----------
%

printf("%d", 12)
printf("%d\n%d", 12, 42)
printf("%d\n%d ---> %s", 12, 42, "Hello")

*/



