/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotations.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkierbel <rkierbel@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 13:56:27 by rkierbel          #+#    #+#             */
/*   Updated: 2021/06/14 13:56:34 by rkierbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	reverse_rotate(t_list **lst, char *print)
{
	t_list	*tmp;
	t_list	*tmp2;

	if (!(*lst) || !(*lst)->next)
		return ;
	else
	{
		tmp = *lst;
		tmp2 = *lst;
		while (tmp->next)
		{
			if (tmp->next->next)
				tmp2 = tmp2->next;
			tmp = tmp->next;
		}
		tmp2->next = NULL;
		tmp->next = *lst;
		*lst = tmp;
	}
	ft_putstr_fd(print, 1);
}

void	reverse_rotate_both(t_list **a, t_list **b)
{
	reverse_rotate(a, "");
	reverse_rotate(b, "");
	ft_putstr_fd("rrr\n", 1);
}

void	rotate(t_list **lst, char *print)
{
	t_list	*tmp;
	t_list	*tmp2;

	if (!(*lst) || !(*lst)->next)
		return ;
	else
	{
		tmp = *lst;
		tmp2 = (*lst)->next;
		while ((*lst)->next)
			*lst = (*lst)->next;
		(*lst)->next = tmp;
		tmp->next = NULL;
		*lst = tmp2;
	}
	ft_putstr_fd(print, 1);
}

void	rotate_both(t_list **a, t_list **b)
{
	rotate(a, "");
	rotate(b, "");
	ft_putstr_fd("rr\n", 1);
}
