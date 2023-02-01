/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbonnefo <lbonnefo@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 10:25:46 by lbonnefo          #+#    #+#             */
/*   Updated: 2022/12/07 09:19:29 by lbonnefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_conversion(int a, va_list ap, const char *format, int *rtn);

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		a;
	int		rtn;

	va_start(ap, format);
	a = 0;
	rtn = 0;
	while (format[a] != '\0')
	{
		if (format[a] == '%')
		{
			a++;
			if (format[a] == '\0')
				return (rtn);
			ft_conversion(a, ap, format, &rtn);
		}
		else
			ft_putchar_fd_printf(format[a], 1, &rtn);
		a++;
	}
	va_end(ap);
	return (rtn);
}

static void	ft_conversion(int a, va_list ap, const char *format, int *rtn)
{
	if (format[a] == 'c')
		ft_putchar_fd_printf(va_arg(ap, int), 1, rtn);
	else if (format[a] == 's')
		ft_is_str(va_arg(ap, char *), 1, rtn);
	else if (format[a] == 'p')
		ft_is_ptr(va_arg(ap, void *), 1, rtn);
	else if (format[a] == 'd' || format[a] == 'i')
		ft_is_int(va_arg(ap, int), 1, rtn);
	else if (format[a] == 'u')
		ft_is_unsigned(va_arg(ap, unsigned int), 1, rtn);
	else if (format[a] == 'x')
		ft_is_hex(va_arg(ap, unsigned int), "0123456789abcdef", 1, rtn);
	else if (format[a] == 'X')
		ft_is_hex(va_arg(ap, unsigned int), "0123456789ABCDEF", 1, rtn);
	else if (format[a] == '%')
		ft_putchar_fd_printf('%', 1, rtn);
}
