/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataher <ataher@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 09:13:48 by ataher            #+#    #+#             */
/*   Updated: 2024/09/10 09:15:26 by ataher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	int	ft_hexlen(unsigned	int num)
{
	int	len;

	len = 0;
	while (num != 0)
	{
		len++;
		num = num / 16;
	}
	return (len);
}

static	void	ft_puthex_writer(unsigned int num, const char format, int fd)
{
	if (num >= 16)
	{
		ft_puthex_writer(num / 16, format, fd);
		ft_puthex_writer(num % 16, format, fd);
	}
	else
	{
		if (num <= 9)
			ft_putchar_fd((num + '0'), fd);
		else
		{
			if (format == 'x')
				ft_putchar_fd((num - 10 + 'a'), fd);
			if (format == 'X')
				ft_putchar_fd((num - 10 + 'A'), fd);
		}
	}
}

int	ft_puthex_fd(unsigned int num, const char format, int fd)
{
	if (num == 0)
		return (write(1, "0", 1));
	else
		ft_puthex_writer(num, format, fd);
	return (ft_hexlen(num));
}
