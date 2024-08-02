/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_cost.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssuchane <ssuchane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 16:11:38 by ssuchane          #+#    #+#             */
/*   Updated: 2024/08/02 19:07:36 by ssuchane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	calculate_temp_cost(t_l *a, t_l *b, t_l **a_node, t_l **b_node)
{
	int	temp;
	int	a_diff;
	int	b_diff;

	temp = b->index;
	if (a->index > b->index)
		temp = a->index;
	if (b->index + (stack_size(*a_node) - a->index) < temp)
		temp = b->index + (stack_size(*a_node) - a->index);
	if (a->index + (stack_size(*b_node) - b->index) < temp)
		temp = a->index + (stack_size(*b_node) - b->index);
	a_diff = stack_size(*a_node) - a->index;
	b_diff = stack_size(*b_node) - b->index;
	if (a_diff > b_diff && a_diff < temp)
		temp = a_diff;
	else if (b_diff >= a_diff && b_diff < temp)
		temp = b_diff;
	return (temp);
}

void	calculate_push_costs(t_l **a_node, t_l **b_node)
{
	t_l	*b;
	t_l	*a;

	b = *b_node;
	while (b != NULL)
	{
		a = b->target_node;
		b->push_cost = calculate_temp_cost(a, b, a_node, b_node);
		b = b->next;
	}
}