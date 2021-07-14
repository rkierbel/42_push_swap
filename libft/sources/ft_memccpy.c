/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkierbel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 14:10:00 by rkierbel          #+#    #+#             */
/*   Updated: 2021/04/02 14:25:23 by rkierbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t				i;
	unsigned char		*a;
	const unsigned char	*b;

	i = 0;
	if (dst == NULL && src == NULL)
		return (NULL);
	a = (unsigned char *)dst;
	b = (const unsigned char *)src;
	while (i < n)
	{
		a[i] = b[i];
		if (b[i] == (const unsigned char)c)
		{
			i++;
			return (dst + i);
		}
		i++;
	}
	return (NULL);
}
