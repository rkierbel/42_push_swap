/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkierbel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 17:47:52 by rkierbel          #+#    #+#             */
/*   Updated: 2021/04/03 18:05:37 by rkierbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long	ft_cutnbr(long n)
{
	long	size;

	if (n == 0)
		return (1);
	size = 0;
	if (n < 0)
	{
		size++;
		n = -n;
	}
	while (n != 0)
	{
		n /= 10;
		size++;
	}
	return (size++);
}

int	ft_sign(int n)
{
	if (n < 0)
		return (1);
	return (0);
}

char	*ft_itoa(int n)
{
	long	n_long;
	long	len;
	char	*str;

	n_long = n;
	len = ft_cutnbr(n_long);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (str == NULL)
		return (NULL);
	str[len] = '\0';
	len--;
	if (n_long < 0)
		n_long = -n_long;
	while (len >= 0)
	{
		str[len] = (n_long % 10) + '0';
		len--;
		n_long /= 10;
	}
	if (ft_sign(n))
		str[0] = '-';
	return (str);
}
