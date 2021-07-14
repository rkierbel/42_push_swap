/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkierbel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 11:58:25 by rkierbel          #+#    #+#             */
/*   Updated: 2021/04/02 15:10:21 by rkierbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*p_dst;
	const unsigned char	*p_src;

	if (dst == NULL && src == NULL)
		return (NULL);
	i = 0;
	p_dst = (unsigned char *)dst;
	p_src = (const unsigned char *)src;
	while (i < n)
	{
		p_dst[i] = p_src[i];
		i++;
	}
	return (dst);
}
