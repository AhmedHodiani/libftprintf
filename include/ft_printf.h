#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>

int	ft_printf(const char *format, ...);
int	ft_putaddress_fd(void *address, int fd);
int	ft_putnbr_fd(int n, int fd);
int	ft_putstr_fd(char *s, int fd);
int	ft_puthex_fd(unsigned int num, const char format, int fd);


// helpers
void	hp_puthex_fd(unsigned long num, const char format, int fd);
int		hp_hexlen(unsigned	long num);
int		hp_putchar_fd(char c, int fd);
size_t	hp_strlen(char const *s);

#endif