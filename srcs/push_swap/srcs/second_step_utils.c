#include "pushswap.h"

void	rotate_few_b(t_list **b, int nb)
{
	while (nb-- > 0)
		rotate(b, "rb\n");
}

void	reverse_rotate_few_b(t_list **lst, int nb)
{
	while (nb-- > 0)
		reverse_rotate(lst, "rrb\n");
}

void	push_highest(t_list **a, t_list **b, int highest, t_helper_b *h)
{
	lowest_path_second_step(b, highest, size_list(*b));
	push(b, a, "pa\n");
	if (h->from_sd == true)
		swap(*a, "sa\n");
}

void	push_second_highest(t_list **a, t_list **b, int highest, t_helper_b *h)
{
	if (h->reverse == true)
		reverse_rotate_few_b(b, h->lowest_sd_highest);
	else
		rotate_few_b(b, h->lowest_sd_highest);
	push(b, a, "pa\n");
	h->from_sd = true;
	push_highest(a, b, highest, h);
}
