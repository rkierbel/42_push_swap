/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ullitoa_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkierbel <rkierbel@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 14:38:14 by rkierbel          #+#    #+#             */
/*   Updated: 2021/06/14 14:38:17 by rkierbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*put_in_str(unsigned long long int nb, int base, int size, char *s)
{
	while (nb != 0)
	{
		if ((nb % base) < 10)
			s[size - 1] = (nb % base) + 48;
		else
			s[size - 1] = (nb % base) + 55;
		nb /= base;
		size--;
	}
	return (s);
}

char	*ft_ullitoa_base(unsigned long long int nb, int base)
{
	unsigned long long int	tmp;
	int						size;
	char					*str;

	tmp = nb;
	size = 0;
	str = 0;
	if (nb == 0)
		return (ft_strdup("0"));
	while (nb)
	{
		nb /= base;
		size++;
	}
	str = malloc(sizeof(char) * (size + 1));
	if (!str)
		return (NULL);
	str[size] = '\0';
	str = put_in_str(tmp, base, size, str);
	return (str);
}
