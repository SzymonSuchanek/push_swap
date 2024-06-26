/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssuchane <ssuchane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 17:15:09 by eaktimur          #+#    #+#             */
/*   Updated: 2024/06/26 13:56:34 by ssuchane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	handle_input(char **argv, int argc, t_l **a)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
		{
			if (!is_num(argv[i][j]) && !is_sign(argv[i][j]))
				exit_error_free(*a);
			j++;
		}
		if (check_doubles(*a, ft_atoi(argv[i])))
			exit_error();
		populate_a(a, ft_atoi(argv[i]));
		i++;
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

t_l	*find_highest(t_l *head)
{
	long	highest;
	t_l		*highest_node;
	t_l		*current;

	current = head;
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

t_l	*find_second_highest(t_l *head)
{
	t_l		*highest_node;
	t_l		*second_highest_node;
	long	highest;
	long	second_highest;
	t_l		*current;

	if (!head)
		return (NULL);
	highest_node = find_highest(head);
	if (!highest_node)
		return (NULL);
	highest = highest_node->nbr;
	second_highest = LONG_MIN;
	second_highest_node = NULL;
	current = head;
	while (current)
	{
		if (current->nbr > second_highest && current->nbr < highest)
		{
			second_highest = current->nbr;
			second_highest_node = current;
		}
		current = current->next;
	}
	return (second_highest_node);
}
