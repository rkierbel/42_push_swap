/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkierbel <rkierbel@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 13:59:45 by rkierbel          #+#    #+#             */
/*   Updated: 2021/06/14 13:59:46 by rkierbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static void	swap_long(long *a, long *b)
{
	long	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

static int	partition(long arr[], int low, int high)
{
	int	pivot;
	int	i;
	int	j;

	pivot = arr[high];
	i = low - 1;
	j = low;
	while (j <= high - 1)
	{
		if (arr[j] <= pivot)
			swap_long(&arr[++i], &arr[j]);
		j++;
	}
	swap_long(&arr[i + 1], &arr[high]);
	return (i + 1);
}

void	quicksort(long arr[], int low, int high)
{
	int	pivot;

	if (low < high)
	{
		pivot = partition(arr, low, high);
		quicksort(arr, low, pivot - 1);
		quicksort(arr, pivot + 1, high);
	}
}
