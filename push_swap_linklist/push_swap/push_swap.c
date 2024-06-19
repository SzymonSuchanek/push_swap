/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssuchane <ssuchane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 15:24:17 by eaktimur          #+#    #+#             */
/*   Updated: 2024/06/19 18:37:01 by ssuchane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_l	*push_cost(t_l **a_node, t_l **b_node)
{
	t_l	*b;
	t_l	*a;
	t_l	*cheapest;
	int	min_cost;
	int	temp;

	b = *b_node;
	cheapest = NULL;
	min_cost = INT_MAX;
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
		if (b->push_cost < min_cost)
		{
			min_cost = b->push_cost;
			cheapest = b;
		}
		b = b->next;
	}
	return (cheapest);
}

void	execute_operations(t_l **a, t_l **b, t_l *to_push)
{
	t_l	*target;
	int	bigger_index;
	int	leftover;
	int	flag;

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
	if (to_push->index > 0 || target->index > 0)
	{
		if (to_push->index > target->index)
		{
			bigger_index = to_push->index;
			leftover = to_push->index - target->index;
			flag = 1;
		}
		else
		{
			bigger_index = target->index;
			leftover = target->index - to_push->index;
			flag = -1;
		}
		if ((bigger_index + leftover) < to_push->push_cost)
		{
			if (flag == 1)
			{
				if (to_push->median == 1)
					rr(a, b);
				else
					rrr(a, b);
			}
			if (flag == -1)
			{
				if (target->median == 1)
					rr(a, b);
				else
					rrr(a, b);
			}
		}
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
}

int	find_lowest(t_l **stack)
{
	t_l	*lowest;
	t_l	*current;

	lowest = *stack;
	current = *stack;
	while (current != NULL)
	{
		if (current->nbr < lowest->nbr)
			lowest = current;
		current = current->next;
	}
	return (lowest->index);
}

int	find_lowest2(t_l **stack)
{
	t_l	*lowest;
	t_l	*current;

	lowest = *stack;
	current = *stack;
	while (current != NULL)
	{
		if (current->nbr < lowest->nbr)
			lowest = current;
		current = current->next;
	}
	return (lowest->median);
}

void	final_rotate(t_l **a)
{
	int	index;
	int	median;
	int	i;

	index = find_lowest(a);
	median = find_lowest2(a);
	i = 0;
	if (median == -1)
	{
		while (i < (stack_size(*a) - index))
		{
			reverse_rotate(a, 'a');
			i++;
		}
	}
	else if (median == 1)
	{
		while (i < index)
		{
			r(a, 'a');
			i++;
		}
	}
}

void	actual_push_swap(t_l **a, t_l **b)
{
	t_l	*to_push;

	while (stack_size(*a) >= 3)
	{
		if (stack_size(*a) > 3)
		{
			if (*a == find_highest(*a))
				r(a, 'a');
			push_b(a, b);
		}
		else
		{
			three_elem_sort(a);
			while (stack_size(*b) > 0)
			{
				update_indexes(a, b);
				update_targets(a, b);
				to_push = push_cost(a, b); //
				update_median(a);
				update_median(b);
				execute_operations(a, b, to_push); //
				push_a(a, b);
			}
		}
		if (stack_size(*b) == 0)
			break ;
	}
	update_median(a);
	final_rotate(a);
}

void	sizebased_operation(t_l **a, t_l **b)
{
	if (is_sorted(*a))
		exit_free_list(*a);
	if (stack_size(*a) == 2)
		two_elem_sort(*a);
	else if (stack_size(*a) == 3)
		three_elem_sort(a);
	else
		actual_push_swap(a, b);
}

int	main(int argc, char **argv)
{
	t_l	*a;
	t_l	*b;

	a = NULL;
	b = NULL;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (1);
	if (argc == 2)
		ft_split(argv, ' ', &a);
	else if (argc > 2)
		handle_input(argv, argc, &a);
	update_indexes(&a, &b);
	sizebased_operation(&a, &b);
	exit_free_list(a);
	return (0);
}
