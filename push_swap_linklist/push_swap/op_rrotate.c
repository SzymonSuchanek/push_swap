/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_push copy 2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssuchane <ssuchane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 17:54:28 by ssuchane          #+#    #+#             */
/*   Updated: 2024/06/19 17:56:21 by ssuchane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
