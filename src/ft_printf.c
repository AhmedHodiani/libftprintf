/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataher <ataher@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 13:41:49 by ataher            #+#    #+#             */
/*   Updated: 2024/09/10 10:08:01 by ataher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_printf.h"

/*
Allowed:
malloc, free, write,
va_start, va_arg, va_copy, va_end
*/



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
			if (format[i] == 'd' || format[i] == 'i')
				count += ft_putnbr_fd(va_arg(inputs, int), 1);
			if (format[i] == 's')
				count += ft_putstr_fd(va_arg(inputs, char *), 1);
			if (format[i] == 'c')
				count += hp_putchar_fd(va_arg(inputs, int), 1);
			if (format[i] == 'p')
				count += ft_putaddress_fd((void *)va_arg(inputs, void *), 1);
			if (format[i] == 'x' || format[i] == 'X')
				count += ft_puthex_fd(va_arg(inputs, unsigned int), format[i], 1);

			if (format[i] == '%')
				count += hp_putchar_fd('%', 1);
		}
		else
			count += hp_putchar_fd(format[i], 1);
		i++;
	}
	va_end(inputs);
	return (count);
}


// int main() {
// 	int a = 0;
// 	hp_putchar_fd('\n', 1);
// 	hp_putchar_fd('\n', 1);

// 	ft_printf("%p", NULL);
// 	printf("\n\n\n%p\n\n\n", NULL);
// }


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



