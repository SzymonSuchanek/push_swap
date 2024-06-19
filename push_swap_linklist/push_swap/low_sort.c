/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   low_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssuchane <ssuchane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 18:34:34 by ssuchane          #+#    #+#             */
/*   Updated: 2024/06/19 18:35:23 by ssuchane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_l	*find_highest(t_l *stack)
{
	long	highest;
	t_l		*highest_node;
	t_l		*current;

	current = stack;
	if (!current)
		return (NULL);
	highest = LONG_MIN;
	while (current)
	{
		if (current->nbr > highest)
		{
			highest = current->nbr;
			highest_node = current;
		}
		current = current->next;
	}
	return (highest_node);
}

void	two_elem_sort(t_l *a)
{
	t_l	*first;
	t_l	*second;

	first = a;
	second = first->next;
	if (stack_size(a) == 1)
		exit_free_list(a);
	if (stack_size(a) == 2)
	{
		if (first->nbr > second->nbr)
			s(&a, 'a');
	}
}

void	three_elem_sort(t_l **a)
{
	t_l	*highest;

	highest = find_highest(*a);
	if (*a == highest)
		r(a, 'a');
	else if ((*a)->next == highest)
		reverse_rotate(a, 'a');
	if ((*a)->nbr > (*a)->next->nbr)
		s(a, 'a');
	// 	exit_free_list(a);
}
