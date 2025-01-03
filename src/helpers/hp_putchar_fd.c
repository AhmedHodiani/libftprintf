/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hp_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataher <ataher@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 08:04:01 by ataher            #+#    #+#             */
/*   Updated: 2024/12/11 16:15:16 by ataher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	hp_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
	return (1);
}