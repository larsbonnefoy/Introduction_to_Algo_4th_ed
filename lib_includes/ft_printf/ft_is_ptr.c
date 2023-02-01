/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_ptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbonnefo <lbonnefo@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 14:31:15 by lbonnefo          #+#    #+#             */
/*   Updated: 2022/12/07 09:18:34 by lbonnefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_is_hex_long(unsigned long unb, char *base, int fd, int *rtn);

void	ft_is_ptr(void *ptr, int fd, int *rtn)
{
	unsigned long	adrs;

	adrs = (unsigned long)ptr;
	ft_is_str("0x", fd, rtn);
	ft_is_hex_long(adrs, "0123456789abcdef", fd, rtn);
}

static void	ft_is_hex_long(unsigned long unb, char *base, int fd, int *rtn)
{
	if (unb < 16)
		ft_putchar_fd_printf(base[unb], fd, rtn);
	if (unb >= 16)
	{
		ft_is_hex_long(unb / 16, base, fd, rtn);
		ft_is_hex_long(unb % 16, base, fd, rtn);
	}
}
