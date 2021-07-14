/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkierbel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 15:26:55 by rkierbel          #+#    #+#             */
/*   Updated: 2021/04/02 15:58:26 by rkierbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	int					i;
	const unsigned char	*p_s;

	i = 0;
	p_s = (const unsigned char *)s;
	while (n > 0)
	{
		if (p_s[i] == (unsigned char)c)
			return ((void *)(&p_s[i]));
		i++;
		n--;
	}
	return (NULL);
}	
