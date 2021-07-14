/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arguments.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkierbel <rkierbel@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 14:14:14 by rkierbel          #+#    #+#             */
/*   Updated: 2021/06/14 15:22:21 by rudykierb        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

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
				return (false);
			j++;
		}
		i++;
	}
	return (true);
}

static bool	check_duplicate(long arr[], int len)
{
	int	i;

	i = 0;
	while (i < len - 1)
	{
		if (arr[i] == arr[i + 1])
		{
			free(arr);
			return (false);
		}	
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
		{
			free(arr);
			return (false);
		}	
	}
	quicksort(arr, 0, i - 1);
	if (!check_duplicate(arr, i))
		return (false);
	free(arr);
	return (true);
}
