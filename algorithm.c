/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssuchane <ssuchane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 16:11:38 by ssuchane          #+#    #+#             */
/*   Updated: 2024/08/02 19:00:58 by ssuchane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_l	*find_cheapest_node(t_l **b_node)
{
	t_l	*b;
	t_l	*cheapest;
	int	min_cost;

	cheapest = NULL;
	min_cost = INT_MAX;
	b = *b_node;
	while (b != NULL)
	{
		if (b->push_cost < min_cost)
		{
			min_cost = b->push_cost;
			cheapest = b;
		}
		b = b->next;
	}
	return (cheapest);
}

void	continue_operations(t_l **a, t_l **b, t_l *to_push, t_l *target)
{
	while (to_push->index > 0)
	{
		if (to_push->median == 1)
			r(b, 'b');
		else if (to_push->median == -1)
			reverse_rotate(b, 'b');
	}
	while (target->index > 0)
	{
		if (target->median == 1)
			r(a, 'a');
		else if (target->median == -1)
			reverse_rotate(a, 'a');
	}
}

void	execute_operations(t_l **a, t_l **b, t_l *to_push)
{
	t_l	*target;

	target = to_push->target_node;
	while (to_push->index > 0 && target->index > 0)
	{
		if (to_push->median == 1 && target->median == 1)
			rr(a, b);
		else if (to_push->median == -1 && target->median == -1)
			rrr(a, b);
		else
			break ;
	}
	continue_operations(a, b, to_push, target);
}

void	final_rotate(t_l **a)
{
	t_l	*highest;
	t_l	*lowest;
	int	i;
	int	index;

	highest = find_highest(*a);
	lowest = highest->next;
	index = lowest->index;
	i = 0;
	if (lowest->median == -1)
	{
		while (i < (stack_size(*a) - index))
		{
			reverse_rotate(a, 'a');
			i++;
		}
	}
	else if (lowest->median == 1)
	{
		while (i < index)
		{
			r(a, 'a');
			i++;
		}
	}
}
