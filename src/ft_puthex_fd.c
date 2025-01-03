/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataher <ataher@student.42amman.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 09:13:48 by ataher            #+#    #+#             */
/*   Updated: 2025/01/04 02:43:50 by ataher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_puthex_fd(unsigned int num, const char format, int fd)
{
	if (num == 0)
		return (hp_putchar_fd('0', 1));
	else
		hp_puthex_fd(num, format, fd);
	return (hp_hexlen(num));
}
