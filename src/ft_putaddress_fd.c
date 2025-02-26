/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putaddress_fd.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataher <ataher@student.42amman.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 08:03:21 by ataher            #+#    #+#             */
/*   Updated: 2025/01/04 02:43:50 by ataher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_putaddress_fd(void *address, int fd)
{
	unsigned long	addr;

	addr = (unsigned long)address;
	if (addr == 0)
		return (ft_putstr_fd("(nil)", 1));
	hp_putchar_fd('0', fd);
	hp_putchar_fd('x', fd);
	hp_puthex_fd((unsigned long)addr, 'x', fd);
	return (2 + (int)hp_hexlen(addr));
}
