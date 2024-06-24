/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssuchane <ssuchane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 16:11:33 by ssuchane          #+#    #+#             */
/*   Updated: 2024/06/24 16:47:20 by ssuchane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	r(t_l **b, char which)
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
	if (which == 'a')
		write(1, "ra\n", 3);
	else if (which == 'b')
		write(1, "rb\n", 3);
	update_indexes(NULL, b);
}

void	rr(t_l **a, t_l **b)
{
	r(a, 'x');
	r(b, 'x');
	write(1, "rr\n", 3);
}

void	reverse_rotate(t_l **stack, char which)
{
	t_l	*last;
	t_l	*second_last;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	last = *stack;
	while (last->next)
		last = last->next;
	second_last = last->prev;
	second_last->next = NULL;
	last->prev = NULL;
	last->next = *stack;
	(*stack)->prev = last;
	*stack = last;
	if (which == 'a')
		write(1, "rra\n", 4);
	else if (which == 'b')
		write(1, "rrb\n", 4);
	update_indexes(NULL, stack);
}

void	rrr(t_l **a, t_l **b)
{
	reverse_rotate(a, 'x');
	reverse_rotate(b, 'x');
	write(1, "rrr\n", 4);
}
