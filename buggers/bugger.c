/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bugger.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataher <ataher@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 09:52:34 by ataher            #+#    #+#             */
/*   Updated: 2024/12/11 16:15:16 by ataher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libftprintf.h"

static void	hp_bugger(char *format, va_list inputs)
{
	int		i;

	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
			hp_printf(format[++i], inputs);
		else
			hp_putchar_fd(format[i], 1);
		i++;
	}
	va_end(inputs);
}

void	bugger_cmd(char *format, ...)
{
	va_list	inputs;

	va_start(inputs, format);
	ft_printf(BLUE);
	ft_printf(">> ");
	ft_printf(RESET);
	hp_bugger(format, inputs);
	ft_printf("\n");
}

void	bugger_info(char *format, ...)
{
	va_list	inputs;

	va_start(inputs, format);
	ft_printf(GRAY);
	ft_printf("[INFO]>> ");
	ft_printf(RESET);
	hp_bugger(format, inputs);
	ft_printf("\n");
}

void	bugger_error(char *format, ...)
{
	va_list	inputs;

	va_start(inputs, format);
	ft_printf(RED);
	ft_printf("[ERROR]>> ");
	hp_bugger(format, inputs);
	ft_printf(RESET);
	ft_printf("\n");
}

void	bugger_box(char *format, ...)
{
	va_list	inputs;

	va_start(inputs, format);
	ft_printf(GRAY);
	ft_printf("╔═══════════════════════##-\n");
	ft_printf("║ \n");
	ft_printf("║ ");
	ft_printf(RESET);
	hp_bugger(format, inputs);
	ft_printf(GRAY);
	ft_printf("\n║");
	ft_printf("\n╚═══════════════════════##-\n");
	ft_printf(RESET);
}

// void	bugger_cute(char *format, ...)
// {
// 	va_list	inputs;

// 	va_start(inputs, format);
// 	ft_printf(MAGENTA);
// 	ft_printf("[CUTE 🍇]>> ");
// 	hp_bugger(format, inputs);
// 	ft_printf(RESET);
// 	ft_printf("\n");
// }

// void	bugger_warning(char *format, ...)
// {
// 	va_list	inputs;

// 	va_start(inputs, format);
// 	ft_printf(BRIGHT_YELLOW);
// 	ft_printf("[WARNING]>> ");
// 	hp_bugger(format, inputs);
// 	ft_printf(RESET);
// 	ft_printf("\n");
// }
// int main()
// {
//	 bugger_cmd("hello %s %d", "world", 23);
//	 bugger_info("hello %s %d", "world", 23);
//	 bugger_error("hello %s %d", "world", 23);
//	 bugger_warning("hello %s %d", "world", 23);
//	 bugger_cute("hello %s %d", "world", 23);
//	 bugger_box("I am a box %s %d", "world", 23);
// }
