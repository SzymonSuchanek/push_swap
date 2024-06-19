/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssuchane <ssuchane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 18:20:46 by ssuchane          #+#    #+#             */
/*   Updated: 2024/06/19 18:26:30 by ssuchane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_l	*find_last_node(t_l *a)
{
	t_l	*node;

	if (!a)
		return (NULL);
	node = a;
	while (node->next)
		node = node->next;
	return (node);
}

void	populate_a(t_l **a, int n)
{
	t_l	*node;
	t_l	*last_node;

	node = malloc(sizeof(t_l));
	if (!node)
		exit_error();
	node->nbr = n;
	node->next = NULL;
	if (!*a)
	{
		*a = node;
		node->prev = NULL;
	}
	else
	{
		last_node = find_last_node(*a);
		last_node->next = node;
		node->prev = last_node;
	}
}

int	stack_size(t_l *a)
{
	t_l	*current;
	int	count;

	if (!a || !a)
		return (0);
	current = a;
	count = 0;
	while (current && current->index != 0)
		current = current->next;
	if (!current)
		return (0);
	while (current)
	{
		count++;
		current = current->next;
	}
	return (count);
}

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
