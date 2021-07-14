/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_and_error.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkierbel <rkierbel@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 14:17:49 by rkierbel          #+#    #+#             */
/*   Updated: 2021/06/14 14:17:56 by rkierbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	exit_faillure(char *error)
{
	ft_putstr_fd(error, 2);
	exit(1);
}

void	free_list(t_list *a, t_list *b)
{
	t_list	*tmp;

	while (a)
	{
		tmp = a;
		a = a->next;
		free(tmp);
	}
	while (b)
	{
		tmp = b;
		b = b->next;
		free(tmp);
	}
}

t_list	*last_node(t_list *node)
{
	while (node->next)
		node = node->next;
	return (node);
}

bool	create_node(t_list **list, int nb)
{
	t_list	*new;
	t_list	*tmp;

	tmp = *list;
	new = malloc(sizeof(t_list));
	if (!new)
		return (0);
	else
	{
		new->content = nb;
		new->next = NULL;
		if (*list)
		{
			tmp = last_node(tmp);
			tmp->next = new;
		}
		else
			*list = new;
	}
	return (1);
}
