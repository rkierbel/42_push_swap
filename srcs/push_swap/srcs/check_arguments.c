/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arguments.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkierbel <rkierbel@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 13:58:53 by rkierbel          #+#    #+#             */
/*   Updated: 2021/06/14 15:20:08 by rudykierb        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static int	lenght_array(char *array[])
{
	int	i;

	i = 0;
	while (array[i])
		i++;
	return (i);
}

static bool	check_digits(char *args[])
{
	int		i;
	int		j;
	int		neg;

	i = 0;
	while (args[i])
	{
		j = 0;
		neg = 0;
		while (args[i][j])
		{
			if (args[i][0] == '-' && neg == 0)
			{
				j++;
				neg = 1;
			}	
			if (!ft_isdigit(args[i][j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

static bool	check_duplicate(long arr[], int len)
{
	int	i;

	i = 0;
	while (i < len - 1)
	{
		if (arr[i] == arr[i + 1])
			return (false);
		i++;
	}
	return (true);
}

bool	check_arguments(char *args[])
{
	int		i;
	long	*arr;

	if (!check_digits(args))
		return (false);
	i = 0;
	arr = malloc(sizeof(long) * lenght_array(args));
	if (!arr)
		return (false);
	while (args[i])
	{
		arr[i] = ft_atol(args[i]);
		if (arr[i] > 2147483647 || arr[i++] < -2147483648)
			return (false);
	}
	quicksort(arr, 0, i - 1);
	if (!check_duplicate(arr, i))
	{
		free(arr);
		return (false);
	}
	free(arr);
	return (true);
}
