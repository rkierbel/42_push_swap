/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkierbel <rkierbel@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 14:06:00 by rkierbel          #+#    #+#             */
/*   Updated: 2021/06/14 14:06:11 by rkierbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static int	find_highest(t_list *lst)
{
	int	highest;

	highest = INT_MIN;
	while (lst != NULL)
	{
		if (highest < lst->content)
			highest = lst->content;
		lst = lst->next;
	}
	return (highest);
}

void	sort_three_number(t_list **a)
{
	while (check_sort(*a) == false)
	{
		if ((*a)->content == find_highest(*a))
			rotate(a, "ra\n");
		else if ((*a)->content > (*a)->next->content)
			swap(*a, "sa\n");
		else
			reverse_rotate(a, "rra\n");
	}
}

long	*insert_into_array(t_list *lst, int size)
{
	long	*arr;
	int		i;

	i = 0;
	arr = malloc(sizeof(long) * size);
	if (!arr)
		exit_faillure("Error\n");
	while (lst)
	{
		arr[i++] = lst->content;
		lst = lst->next;
	}
	return (arr);
}
