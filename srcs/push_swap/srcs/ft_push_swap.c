/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkierbel <rkierbel@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 13:54:50 by rkierbel          #+#    #+#             */
/*   Updated: 2021/06/14 13:54:53 by rkierbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	push(t_list **from, t_list **to, char *print)
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
	ft_putstr_fd(print, 1);
}

void	swap(t_list *lst, char *print)
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
	ft_putstr_fd(print, 1);
}

void	swap_both(t_list *a, t_list *b)
{
	swap(a, "");
	swap(b, "");
	ft_putstr_fd("ss\n", 1);
}
