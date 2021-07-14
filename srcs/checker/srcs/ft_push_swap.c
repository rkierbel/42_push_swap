/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkierbel <rkierbel@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 14:12:47 by rkierbel          #+#    #+#             */
/*   Updated: 2021/06/14 14:13:15 by rkierbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	push(t_list **from, t_list **to)
{
	t_list	*tmp;

	if (!(*from))
		return ;
	else
	{
		tmp = *from;
		*from = (*from)->next;
		tmp->next = *to;
		*to = tmp;
	}
}

void	swap(t_list *lst)
{
	int	tmp;

	if (!lst || !lst->next)
		return ;
	else
	{
		tmp = lst->content;
		lst->content = lst->next->content;
		lst->next->content = tmp;
	}
}

void	swap_both(t_list *a, t_list *b)
{
	swap(a);
	swap(b);
}
