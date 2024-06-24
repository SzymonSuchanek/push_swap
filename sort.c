/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssuchane <ssuchane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 17:15:55 by eaktimur          #+#    #+#             */
/*   Updated: 2024/06/24 19:03:32 by ssuchane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_l *a)
{
	t_l	*current;

	if (!a)
		return (1);
	current = a;
	while (current && current->index != 0)
		current = current->next;
	if (!current)
		return (1);
	while (current->next)
	{
		if (current->nbr > current->next->nbr)
			return (0);
		current = current->next;
	}
	return (1);
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
	update_indexes(&a, NULL);
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
}
