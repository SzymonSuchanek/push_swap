/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssuchane <ssuchane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 16:11:38 by ssuchane          #+#    #+#             */
/*   Updated: 2024/06/26 13:56:14 by ssuchane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	calculate_push_costs(t_l **a_node, t_l **b_node)
{
	t_l	*b;
	t_l	*a;
	int	temp;

	b = *b_node;
	while (b != NULL)
	{
		a = b->target_node;
		b->push_cost = 0;
		temp = a->index + b->index;
		if (b->index + (stack_size(*a_node) - a->index) < temp)
			temp = b->index + (stack_size(*a_node) - a->index);
		if (a->index + (stack_size(*b_node) - b->index) < temp)
			temp = a->index + (stack_size(*b_node) - b->index);
		if ((stack_size(*a_node) - a->index) + (stack_size(*b_node)
				- b->index) < temp)
			temp = (stack_size(*a_node) - a->index) + (stack_size(*b_node)
					- b->index);
		b->push_cost = temp;
		b = b->next;
	}
}

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
