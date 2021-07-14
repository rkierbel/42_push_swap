/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotations.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rudykierbel <rkierbel@student.s19.be>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 15:01:12 by rudykierb         #+#    #+#             */
/*   Updated: 2021/06/14 15:01:16 by rudykierb        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	reverse_rotate(t_list **lst)
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
}

void	reverse_rotate_both(t_list **a, t_list **b)
{
	reverse_rotate(a);
	reverse_rotate(b);
}

void	rotate(t_list **lst)
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
}

void	rotate_both(t_list **a, t_list **b)
{
	rotate(a);
	rotate(b);
}
