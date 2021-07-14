/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_delspace.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkierbel <rkierbel@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 14:35:32 by rkierbel          #+#    #+#             */
/*   Updated: 2021/06/14 14:35:37 by rkierbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_delspace(char *str)
{
	size_t	n;
	size_t	i;

	i = 0;
	n = 0;
	while (i < ft_strlen(str))
	{
		if (!ft_isspace(str[i]))
			str[n++] = str[i];
		i++;
	}
	str[n] = '\0';
}
