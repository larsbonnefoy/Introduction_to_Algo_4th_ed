/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbonnefo <lbonnefo@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 10:54:17 by lbonnefo          #+#    #+#             */
/*   Updated: 2022/12/07 09:18:17 by lbonnefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_is_int(int nb, int fd, int *rtn)
{
	unsigned int	unb;

	unb = nb;
	if (nb < 0)
	{
		ft_putchar_fd_printf('-', fd, rtn);
		unb = -nb;
	}
	if (unb < 10)
	{
		unb += '0';
		ft_putchar_fd_printf(unb, 1, rtn);
	}
	else
	{
		ft_is_int(unb / 10, fd, rtn);
		ft_is_int(unb % 10, fd, rtn);
	}
}
