/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssuchane <ssuchane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 16:11:33 by ssuchane          #+#    #+#             */
/*   Updated: 2024/06/24 18:27:52 by ssuchane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	s(t_l **stack, char which)
{
	t_l	*first;
	t_l	*second;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	first = *stack;
	second = first->next;
	first->next = second->next;
	if (second->next)
		second->next->prev = first;
	second->next = first;
	second->prev = first->prev;
	first->prev = second;
	*stack = second;
	if (which == 'a')
		write(1, "sa\n", 3);
	else if (which == 'b')
		write(1, "sb\n", 3);
	update_indexes(NULL, stack);
}

void	ss(t_l **a, t_l **b)
{
	s(a, 'x');
	s(b, 'x');
	write(1, "ss\n", 3);
}

void	push_a(t_l **a, t_l **b)
{
	t_l	*node_to_move;

	if (!b || !*b)
		return ;
	node_to_move = *b;
	*b = node_to_move->next;
	if (*b)
		(*b)->prev = NULL;
	node_to_move->next = *a;
	if (*a)
		(*a)->prev = node_to_move;
	node_to_move->prev = NULL;
	*a = node_to_move;
	write(1, "pa\n", 3);
	update_indexes(a, b);
}

void	push_b(t_l **a, t_l **b)
{
	t_l	*node_to_move;

	if (!a || !*a)
		return ;
	node_to_move = *a;
	*a = node_to_move->next;
	if (*a)
		(*a)->prev = NULL;
	node_to_move->next = *b;
	if (*b)
		(*b)->prev = node_to_move;
	node_to_move->prev = NULL;
	*b = node_to_move;
	write(1, "pb\n", 3);
	update_indexes(a, b);
}
