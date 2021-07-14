/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkierbel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 10:43:16 by rkierbel          #+#    #+#             */
/*   Updated: 2021/04/03 10:58:21 by rkierbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	unsigned char	*object;
	unsigned long	i;

	object = malloc(count * size);
	if (object == NULL)
		return (NULL);
	i = 0;
	while (i < size * count)
	{
		object[i] = 0;
		i++;
	}
	return ((void *)(object));
}	
