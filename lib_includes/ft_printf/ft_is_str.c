/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbonnefo <lbonnefo@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 10:49:39 by lbonnefo          #+#    #+#             */
/*   Updated: 2022/12/07 09:18:45 by lbonnefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_is_str(char *s, int fd, int *rtn)
{
	int	len;

	if (s == NULL)
		s = "(null)";
	len = ft_strlen_printf(s);
	*rtn += len;
	write(fd, s, len);
}
