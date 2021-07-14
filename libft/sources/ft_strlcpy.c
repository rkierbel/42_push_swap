/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkierbel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 17:15:28 by rkierbel          #+#    #+#             */
/*   Updated: 2021/04/07 16:55:59 by rkierbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	index;
	size_t	src_len;

	src_len = 0;
	index = 0;
	if (src == NULL)
		return (0);
	while (src[src_len] != '\0')
		src_len++;
	while (src[index] != '\0' && index < dstsize - 1)
	{
		if (index < dstsize - 1 && dstsize > 0)
			dst[index] = src[index];
		index++;
	}
	if (dstsize > 0)
		dst[index] = '\0';
	return (src_len);
}
