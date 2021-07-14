/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkierbel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 17:01:34 by rkierbel          #+#    #+#             */
/*   Updated: 2021/04/07 09:51:22 by rkierbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*str;
	char	*last;
	int		i;

	i = 0;
	str = (char *)s;
	last = NULL;
	while (str[i])
	{
		if (str[i] == (char)c)
			last = &str[i];
		i++;
	}
	if (c == '\0')
		return (&str[i]);
	return (last);
}	
