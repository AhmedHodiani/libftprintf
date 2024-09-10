#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>

int	ft_printf(const char *format, ...);
int	ft_putaddress_fd(void *address, int fd);
int	ft_putnbr_fd(int n, int fd);
int	ft_putchar_fd(char c, int fd);
int	ft_putstr_fd(char *s, int fd);

size_t	ft_strlen(char const *s);

#endif
