/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataher <ataher@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 08:07:41 by ataher            #+#    #+#             */
/*   Updated: 2024/09/10 08:33:04 by ataher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
