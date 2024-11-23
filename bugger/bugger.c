#include "../include/ft_printf.h"

static void    hp_bugger(char *format, va_list inputs)
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

void bugger_info(char *format, ...)
{
	va_list	inputs;
	va_start(inputs, format);

    ft_printf(GRAY);
    ft_printf("%s %s() [%d] >> ", __FILE__, __func__, __LINE__);
    ft_printf(RESET);
    hp_bugger(format, inputs);
    ft_printf("\n");
}


void bugger_error(char *format, ...)
{
	va_list	inputs;
	va_start(inputs, format);

    ft_printf(RED);
    ft_printf("%s %s() [%d] >> ", __FILE__, __func__, __LINE__);
    ft_printf(RESET);
    hp_bugger(format, inputs);
    ft_printf("\n");
}

void bugger_box(char *format, ...)
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

void bugger_cute(char *format, ...)
{
    va_list	inputs;
    va_start(inputs, format);

    ft_printf(MAGENTA);
    ft_printf("🍇>> ");
    hp_bugger(format, inputs);
    ft_printf(RESET);
    ft_printf("\n");
}

void bugger_warning(char *format, ...)
{
    va_list	inputs;
    va_start(inputs, format);

    ft_printf(BRIGHT_YELLOW);
    ft_printf(">> ");
    hp_bugger(format, inputs);
    ft_printf(RESET);
    ft_printf("\n");
}