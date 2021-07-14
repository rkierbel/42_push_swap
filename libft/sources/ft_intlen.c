/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkierbel <rkierbel@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 14:37:11 by rkierbel          #+#    #+#             */
/*   Updated: 2021/06/14 14:37:13 by rkierbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_intlen(int nb, int base)
{
	size_t			len;
	unsigned int	nb_u;

	len = 1;
	if (nb < 0)
	{
		nb_u = -nb;
		len = 2;
	}
	else
		nb_u = nb;
	while ((nb_u / base) > 0)
	{
		nb_u /= base;
		len++;
	}
	return (len);
}
