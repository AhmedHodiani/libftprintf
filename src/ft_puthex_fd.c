/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataher <ataher@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 09:13:48 by ataher            #+#    #+#             */
/*   Updated: 2024/09/10 10:37:30 by ataher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex_fd(unsigned int num, const char format, int fd)
{
	if (num == 0)
		return (write(1, "0", 1));
	else
		hp_puthex_fd(num, format, fd);
	return (hp_hexlen(num));
}
