/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_step_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkierbel <rkierbel@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 14:01:47 by rkierbel          #+#    #+#             */
/*   Updated: 2021/06/14 14:01:58 by rkierbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	rotate_few(t_list **lst, int nb, char *print)
{
	rotate(lst, print);
	while (--nb > 0)
		rotate(lst, print);
}

void	reverse_rotate_few(t_list **lst, int nb, char *print)
{
	reverse_rotate(lst, print);
	while (--nb >= 0)
		reverse_rotate(lst, print);
}

int	find_mid(t_list *lst, int size)
{
	long	*arr;
	int		i;

	arr = insert_into_array(lst, size);
	quicksort(arr, 0, size - 1);
	i = (int)arr[size / 2];
	free(arr);
	arr = NULL;
	return (i);
}
