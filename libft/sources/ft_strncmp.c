/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkierbel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 17:09:49 by rkierbel          #+#    #+#             */
/*   Updated: 2021/04/02 17:41:56 by rkierbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*p_s1;
	unsigned char	*p_s2;

	i = 0;
	p_s1 = (unsigned char *)s1;
	p_s2 = (unsigned char *)s2;
	if (p_s1 == p_s2 || n == 0)
		return (0);
	while (i < n && (p_s1[i] != '\0' || p_s2[i] != '\0'))
	{
		if (p_s1[i] != p_s2[i])
			return ((int)(p_s1[i] - p_s2[i]));
		i++;
	}
	return (0);
}
