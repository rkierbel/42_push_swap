/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkierbel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 14:47:53 by rkierbel          #+#    #+#             */
/*   Updated: 2021/04/09 13:29:07 by rkierbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t				i;
	unsigned char		*p_dst;	
	const unsigned char	*p_src;

	i = 0;
	if (dst == NULL && src == NULL)
		return (NULL);
	if (src == dst)
		return (dst);
	p_dst = (unsigned char *)dst;
	p_src = (const unsigned char *)src;
	if (p_src < p_dst)
	{
		i++;
		while (i <= len)
		{
			p_dst[len - i] = p_src[len - i];
			i++;
		}
	}
	else
		ft_memcpy(p_dst, p_src, len);
	return (dst);
}
