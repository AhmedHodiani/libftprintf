/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hp_puthex_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataher <ataher@student.42amman.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 09:39:08 by ataher            #+#    #+#             */
/*   Updated: 2025/01/04 02:43:54 by ataher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	hp_puthex_fd(unsigned long num, const char format, int fd)
{
	if (num >= 16)
	{
		hp_puthex_fd(num / 16, format, fd);
		hp_puthex_fd(num % 16, format, fd);
	}
	else
	{
		if (num <= 9)
			hp_putchar_fd((num + '0'), fd);
		else
		{
			if (format == 'x')
				hp_putchar_fd((num - 10 + 'a'), fd);
			if (format == 'X')
				hp_putchar_fd((num - 10 + 'A'), fd);
		}
	}
}
