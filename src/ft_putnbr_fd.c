/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataher <ataher@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 08:07:41 by ataher            #+#    #+#             */
/*   Updated: 2024/09/10 14:35:44 by ataher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_fd(int n, int fd)
{
	int	count;

	count = 0;
	if (n == -2147483648)
		return (ft_putstr_fd("-2147483648", fd));
	if (n < 0)
	{
		count += hp_putchar_fd('-', fd);
		n = -n;
	}
	if (n > 9)
		count += ft_putnbr_fd(n / 10, fd);
	count += hp_putchar_fd(n % 10 + '0', fd);
	return (count);
}
