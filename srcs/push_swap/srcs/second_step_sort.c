/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   second_step_sort.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkierbel <rkierbel@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 14:03:29 by rkierbel          #+#    #+#             */
/*   Updated: 2021/06/14 14:03:30 by rkierbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	lowest_path_second_step(t_list **b, int highest, int size)
{
	int		i;
	int		top;
	int		bot;
	long	*arr;

	i = 0;
	top = 0;
	bot = 1;
	arr = insert_into_array(*b, size);
	while (arr[i++] != highest)
		top++;
	while (arr[--size] != highest)
		bot++;
	if (top <= bot)
		rotate_few_b(b, top);
	else
		reverse_rotate_few_b(b, bot);
	free(arr);
	arr = NULL;
}

int	select_highest(t_list **b, int nb, t_helper_b *h, bool is_sd_highest)
{
	int		i;
	int		top;
	int		bot;
	int		tpm_size;
	long	*arr;

	i = 0;
	top = 0;
	bot = 1;
	tpm_size = h->size;
	arr = insert_into_array(*b, h->size);
	while (arr[i++] != nb)
		top++;
	while (arr[--h->size] != nb)
		bot++;
	h->size = tpm_size;
	free(arr);
	if (top <= bot)
		return (top);
	else
	{
		if (is_sd_highest == true)
			h->reverse = true;
		return (bot);
	}	
}

void	second_step_sort(t_list **a, t_list **b)
{
	long		*arr;
	t_helper_b	h;

	while (*b)
	{
		ft_bzero(&h, sizeof(t_helper_b));
		h.size = size_list(*b);
		arr = insert_into_array(*b, h.size);
		quicksort(arr, 0, h.size - 1);
		h.lowest_highest = select_highest(b, arr[h.size - 1], &h, false);
		if (h.size != 1)
			h.lowest_sd_highest = select_highest(b, arr[h.size - 2],
					&h, true);
		if (h.lowest_sd_highest < h.lowest_highest)
			push_second_highest(a, b, arr[h.size - 1], &h);
		else
			push_highest(a, b, arr[h.size - 1], &h);
		free(arr);
	}
}
