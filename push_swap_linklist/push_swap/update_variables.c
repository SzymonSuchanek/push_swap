/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_variables.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssuchane <ssuchane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 18:32:06 by ssuchane          #+#    #+#             */
/*   Updated: 2024/06/19 18:33:01 by ssuchane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	update_indexes(t_l **a, t_l **b)
{
	t_l	*current;
	int	index;

	if (a && *a)
	{
		current = *a;
		index = 0;
		while (current)
		{
			current->index = index++;
			current = current->next;
		}
	}
	if (b && *b)
	{
		current = *b;
		index = 0;
		while (current)
		{
			current->index = index++;
			current = current->next;
		}
	}
}

void	update_targets(t_l **a, t_l **b)
{
	t_l	*b_current;
	t_l	*a_current;
	t_l	*closest;

	b_current = *b;
	while (b_current != NULL)
	{
		closest = NULL;
		a_current = *a;
		while (a_current != NULL)
		{
			if (a_current->nbr > b_current->nbr)
			{
				if (closest == NULL || a_current->nbr < closest->nbr)
				{
					closest = a_current;
				}
			}
			a_current = a_current->next;
		}
		if (closest == NULL)
			closest = find_highest(*a);
		b_current->target_node = closest;
		b_current = b_current->next;
	}
}

void	update_median(t_l **stack)
{
	t_l	*current;
	int	total_nodes;
	int	index;
	int	mid;

	if (stack == NULL || *stack == NULL)
	{
		return ;
	}
	current = *stack;
	total_nodes = stack_size(current);
	while (current != NULL)
	{
		index = current->index;
		mid = total_nodes / 2;
		if (index < mid)
			current->median = 1;
		else
			current->median = -1;
		current = current->next;
	}
}