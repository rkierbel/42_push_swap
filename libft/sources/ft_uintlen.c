/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uintlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkierbel <rkierbel@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 14:37:59 by rkierbel          #+#    #+#             */
/*   Updated: 2021/06/14 14:38:01 by rkierbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_uintlen(unsigned int nb, int base)
{
	size_t	len;

	len = 1;
	while ((nb / base) > 0)
	{
		nb /= base;
		len++;
	}
	return (len);
}
