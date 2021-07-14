/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkierbel <rkierbel@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 13:55:16 by rkierbel          #+#    #+#             */
/*   Updated: 2021/06/14 13:55:18 by rkierbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

bool	check_sort(t_list *a)
{
	while (a->next)
	{
		if (a->content > a->next->content)
			return (false);
		a = a->next;
	}
	return (true);
}

static bool	fill_stack_a(t_list **a, char *args[])
{
	int	i;

	i = 0;
	while (args[i])
	{
		if (!create_node(a, ft_atoi(args[i++])))
		{
			ft_free_array_string(args);
			return (false);
		}	
	}
	ft_free_array_string(args);
	return (true);
}

int	main(int argc, char *argv[])
{	
	char	**seq;
	t_list	*a;
	t_list	*b;

	a = NULL;
	b = NULL;
	if (argc != 1)
	{
		seq = get_arguments(argc, argv);
		if (!check_arguments(seq) || !fill_stack_a(&a, seq))
		{
			free_list(a, b);
			ft_free_array_string(seq);
			exit_faillure("Error\n");
		}	
	}
	else
		return (0);
	if (check_sort(a) == true)
	{
		free_list(a, b);
		return (1);
	}	
	first_step_sort(&a, &b);
	free_list(a, b);
}
