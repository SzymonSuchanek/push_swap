/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssuchane <ssuchane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 14:08:29 by ssuchane          #+#    #+#             */
/*   Updated: 2024/06/14 17:50:21 by ssuchane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_l **a)
{
	t_l	*first;
	t_l	*last;

	if (!*a || !(*a)->next)
		return ;
	first = *a;
	last = find_last_node(*a);
	last->next = first;
	*a = first->next;
	(*a)->prev = NULL;
	last->next->prev = last;
	last->next->next = NULL;
	// Update to ft_printf
	printf("ra\n");

	// t_l *ptr = *a;
	// while (ptr)
	// {
	// 	printf("%d ", ptr->nbr);
	// 	ptr = ptr->next;
	// }
	// printf("\n");
	// ptr = *a;
	// printf("stack size: %d\n", stack_size(*a));
}

void	rb(t_l **b)
{
	t_l	*last;

	if (!*b || !(*b)->next)
		return ;
	last = find_last_node(*b);
	last->next = *b;
	*b = (*b)->next;
	(*b)->prev = NULL;
	last->next->prev = last;
	last->next->next = NULL;
	// update to ft_printf
	printf("rb\n");
}

void	rr(t_l **a, t_l **b)
{
	ra(a);
	rb(b);
}
