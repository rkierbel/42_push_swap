/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_step_sort.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkierbel <rkierbel@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 14:01:07 by rkierbel          #+#    #+#             */
/*   Updated: 2021/06/14 14:01:15 by rkierbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static void	push_reorder(t_list **a, t_list **b, int mid_a)
{
	int	size_b;

	push(a, b, "pb\n");
	size_b = size_list(*b);
	if ((*b)->content < find_mid(*b, size_b) && (*b)->next)
	{
		if ((*a)->content > mid_a)
			rotate_both(a, b);
		else
			rotate(b, "rb\n");
	}
}

static void	shortest_path_first_step(t_list **a, t_list **b, int mid, int size)
{
	int		i;
	int		top;
	int		bot;
	long	*arr;

	i = 0;
	top = 0;
	bot = 0;
	arr = insert_into_array(*a, size);
	while (arr[i++] >= mid)
		top++;
	while (arr[--size] >= mid)
		bot++;
	if (top <= bot)
		rotate_few(a, top, "ra\n");
	else
		reverse_rotate_few(a, bot, "rra\n");
	free(arr);
	arr = NULL;
	push_reorder(a, b, mid);
}

void	first_step_sort(t_list **a, t_list **b)
{
	int	size_a;
	int	mid;
	int	size_chunk;
	int	half;

	size_a = size_list(*a);
	while (size_a > 3)
	{
		size_chunk = 0;
		mid = find_mid(*a, size_a);
		half = size_a / 2;
		while (half--)
		{
			if ((*a)->content < mid)
				push_reorder(a, b, mid);
			else
				shortest_path_first_step(a, b, mid, size_a - size_chunk);
			size_chunk++;
		}
		size_a = size_list(*a);
	}
	sort_three_number(a);
	second_step_sort(a, b);
}
