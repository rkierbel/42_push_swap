/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_array_string.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkierbel <rkierbel@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 14:35:58 by rkierbel          #+#    #+#             */
/*   Updated: 2021/06/14 14:35:59 by rkierbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_free_array_string(char **arr)
{
	int		len;
	int		i;

	len = 0;
	while (arr[len])
		len++;
	i = 0;
	while (i < len)
		ft_free(arr[i++]);
	ft_free(arr);
}
