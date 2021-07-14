/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_delchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkierbel <rkierbel@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 14:35:21 by rkierbel          #+#    #+#             */
/*   Updated: 2021/06/14 14:35:23 by rkierbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_delchar(char *str, char set)
{
	size_t	n;
	size_t	i;

	i = 0;
	n = 0;
	while (i < ft_strlen(str))
	{
		if (str[i] != set)
			str[n++] = str[i];
		i++;
	}
	str[n] = '\0';
}
