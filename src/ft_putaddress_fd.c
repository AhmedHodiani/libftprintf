/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putaddress_fd.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataher <ataher@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 08:03:21 by ataher            #+#    #+#             */
/*   Updated: 2024/09/10 08:26:20 by ataher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_putaddress_fd(void *address, int fd)
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
