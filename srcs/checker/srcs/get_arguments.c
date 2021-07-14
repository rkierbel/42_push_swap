/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_arguments.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkierbel <rkierbel@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 14:15:00 by rkierbel          #+#    #+#             */
/*   Updated: 2021/06/14 14:15:01 by rkierbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static char	**one_line_arguments(char *argv[])
{
	char	**args;

	args = ft_split(argv[1], ' ');
	if (!args)
		exit_faillure("Ft_split : Error\n");
	return (args);
}

static char	**separate_arguments(int argc, char *argv[])
{
	char	**args;
	int		i;

	i = 0;
	args = malloc(sizeof(char *) * argc);
	if (!args)
		exit_faillure("Malloc : Error\n");
	while (argv[i + 1])
	{
		args[i] = ft_strdup(argv[i + 1]);
		if (!args[i])
		{
			ft_free_array_string(args);
			exit_faillure("Ft_strdup : Error\n");
		}	
		i++;
	}
	args[i] = NULL;
	return (args);
}

char	**get_arguments(int argc, char *argv[])
{
	char	**args;

	if (argc == 2)
		args = one_line_arguments(argv);
	else
		args = separate_arguments(argc, argv);
	return (args);
}
