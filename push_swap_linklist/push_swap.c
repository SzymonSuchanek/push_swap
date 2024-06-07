/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssuchane <ssuchane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 18:45:43 by ssuchane          #+#    #+#             */
/*   Updated: 2024/06/07 18:35:30 by ssuchane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	exit_error(void)
{
	printf("Error\n");
	exit(0);
}

void	exit_error_free(t_l *stack)
{
	t_l	*tmp;

	printf("Error\n");
	while (stack)
	{
		tmp = stack;
		stack = stack->next;
		free(tmp);
	}
	exit(0);
}

void	free_list(t_l *list)
{
	t_l	*tmp;

	while (list)
	{
		tmp = list;
		list = list->next;
		free(tmp);
	}
}

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

int	ft_atoi(char *str)
{
	int				i;
	long long int	result;
	int				is_negative;

	i = 0;
	result = 0;
	is_negative = 1;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
		{
			is_negative = -1;
		}
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	if (result > INT_MAX || result < INT_MIN)
		exit_error();
	return ((int)result * is_negative);
}

int	is_num(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	is_sign(char c)
{
	if (c == '+' || c == '-')
		return (1);
	return (0);
}

int	check_doubles(t_l *a, int n)
{
	t_l	*node;

	node = a;
	if (!a)
		return (0);
	while (node)
	{
		if (node->nbr == n)
			exit_error();
		node = node->next;
	}
	return (0);
}

void	ft_split(char **argv, char c, t_l **a)
{
	t_l		*a_list;
	char	*str;
	int		num;
	int		is_num_started;

	a_list = NULL;
	num = 0;
	is_num_started = 0;
	str = argv[1];
	while (*str)
	{
		if (*str == c)
		{
			if (is_num_started)
			{
				if (check_doubles(a_list, num))
					exit_error();
				populate_a(&a_list, num);
				is_num_started = 0;
			}
		}
		else if (is_num(*str))
		{
			if (!is_num_started)
			{
				is_num_started = 1;
				num = 0;
			}
			num = num * 10 + (*str - '0');
		}
		else
			exit_error();
		str++;
	}
	if (is_num_started)
	{
		if (check_doubles(a_list, num))
			exit_error();
		populate_a(&a_list, num);
	}
	*a = a_list;
}

void	handle_input(char **av, int ac, t_l **a)
{
	int	i;
	int	j;

	i = 1;
	while (i < ac)
	{
		j = 0;
		while (av[i][j])
		{
			if (!is_num(av[i][j]) && !is_sign(av[i][j]))
				exit_error();
			j++;
		}
		if (check_doubles(*a, ft_atoi(av[i])))
			exit_error();
		populate_a(a, ft_atoi(av[i]));
		i++;
	}
}

int	is_sorted(t_l *a)
{
	t_l	*node;

	node = a;
	if (node == NULL || node->next == NULL)
		return (1);
	while (node->next != NULL)
	{
		if (node->nbr > node->next->nbr)
		{
			return (0);
		}
		node = node->next;
	}
	return (1);
}

int	stack_size(t_l *stack)
{
	int	count;
	t_l	*current;

	count = 0;
	current = stack;
	while (current)
	{
		count++;
		current = current->next;
	}
	return (count);
}

void	two_elem_sort(t_l *a)
{
	t_l	*first;
	t_l	*second;

	first = a;
	second = first->next;
	if (stack_size(a) == 1)
		exit(0);
	if (stack_size(a) == 2)
	{
		if (first->nbr > second->nbr)
			ra(&a);
	}
	exit(0);
}

t_l	*find_highest(t_l *stack)
{
	long	highest;
	t_l		*highest_node;

	if (!stack)
		return (NULL);
	highest = LONG_MIN;
	while (stack)
	{
		if (stack->nbr > highest)
		{
			highest = stack->nbr;
			highest_node = stack;
		}
		stack = stack->next;
	}
	return (highest_node);
}

void	three_elem_sort(t_l **a)
{
	t_l	*highest;

	highest = find_highest(*a);
	if (*a == highest)
		ra(a);
	else if ((*a)->next == highest)
		rra(a);
	if ((*a)->nbr > (*a)->next->nbr)
		sa(a);
}

t_l	*find_closest_node(t_l *a, t_l *b)
{
	t_l	*closest;
	int	min_diff;
	t_l	*b_node;
	int	diff;

	closest = NULL;
	min_diff = INT_MAX;
	b_node = b;
	while (b_node != NULL)
	{
		diff = b_node->nbr - a->nbr;
		if (diff >= 0 && diff < min_diff)
		{
			min_diff = diff;
			closest = b_node;
		}
		b_node = b_node->next;
	}
	return (closest);
}

t_l	*find_max_node(t_l *b_head)
{
	t_l	*max_node;
	t_l	*b_node;

	max_node = NULL;
	b_node = b_head;
	while (b_node != NULL)
	{
		if (max_node == NULL || b_node->nbr > max_node->nbr)
			max_node = b_node;
		b_node = b_node->next;
	}
	return (max_node);
}

void	update_target_node(t_l **a, t_l **b)
{
	t_l	*current;
	t_l	*closest;
	t_l	*max_node;

	current = *a;
	while (current != NULL)
	{
		closest = find_closest_node(current, *b);
		if (closest != NULL)
			current->target_node = closest;
		else
		{
			max_node = find_max_node(*b);
			current->target_node = max_node;
		}
		current = current->next;
	}
}

void	update_index(t_l **stack)
{
	t_l	*current;
	int	index;

	current = *stack;
	index = 0;
	while (current != NULL)
	{
		current->index = index;
		// printf("%d ", current->index);
		current = current->next;
		index++;
	}
}

void	update_median(t_l **stack)
{
	t_l	*current;
	int	total_nodes;
	int	index;
	int	mid;

	current = *stack;
	total_nodes = stack_size(current);
	while (current != NULL)
	{
		index = current->index;
		mid = total_nodes / 2;
		if (index < mid)
			current->median = 1;
		else if (index > mid)
			current->median = -1;
		else
			current->median = 0;
		current = current->next;
	}
}

void	update_variables(t_l *a, t_l *b)
{
	if (stack_size(a) > 0)
	{
		update_index(&a);
		update_median(&a);
	}
	if (stack_size(b) > 0)
	{
		update_index(&b);
		update_median(&b);
	}
	if (stack_size(a) > 0 && stack_size(b) > 0)
		update_target_node(&a, &b);
	// printf("Index: %d, %d\n", a->index, b->index);
	// printf("Stack size: %d, %d\n", stack_size(a), stack_size(b));
	// printf("Median: %d, %d\n", a->median, b->median);
}

t_l	*find_min_push_cost(t_l *a, t_l *b, t_l **min_node)
{
	t_l	*current;
	int	min_cost;
	int	push_cost;

	min_cost = INT_MAX;
	current = a;
	if (current == NULL)
	{
		*min_node = NULL;
		return (NULL);
	}
	while (current != NULL)
	{
		push_cost = get_push_cost(current, b);
		if (push_cost < min_cost)
		{
			min_cost = push_cost;
			*min_node = current;
		}
		current = current->next;
	}
	return (*min_node);
}

int	get_push_cost(t_l *current, t_l *b)
{
	t_l	*target_node;

	target_node = current->target_node;
	if (current->median == 0 || target_node->median == 0)
	{
		if (current->index > target_node->index)
			current->push_cost = current->index;
		else
			current->push_cost = target_node->index;
	}
	else
	{
		current->push_cost = current->index + target_node->index;
	}
	return (current->push_cost);
}

t_l	*push_cost_total(t_l *a, t_l *b)
{
	t_l	*min_node;

	update_variables(a, b);
	min_node = NULL;
	find_min_push_cost(a, b, &min_node);
	return (min_node);
}

void	simultaneous_rotations(t_l **a, t_l **b, t_l *push_a, t_l *push_b)
{
	if ((push_a->index > 0 && push_b->index > 0)
		&& push_a->median == push_b->median)
	{
		if (push_a->median == 1 || push_a->median == 0)
			rrr(a, b);
		else if (push_a->median == -1)
			rr(a, b);
		push_a->index--;
		push_b->index--;
	}
}

void	individual_rotation_a(t_l **a, t_l *push_a)
{
	if (push_a->index > 0)
	{
		if (push_a->median == 1 || push_a->median == 0)
			ra(a);
		else if (push_a->median == -1 || push_a->median == 0)
			rra(a);
		push_a->index--;
	}
}

void	individual_rotation_b(t_l **b, t_l *push_b)
{
	if (push_b->index > 0)
	{
		if (push_b->median == 1 || push_b->median == 0)
			rb(b);
		else if (push_b->median == -1 || push_b->median == 0)
			rrb(b);
		push_b->index--;
	}
}

void	execute_push_swap_loop(t_l **a, t_l **b, t_l *push_a, t_l *push_b)
{
	while (push_a->index != 0 && push_b->index != 0)
	{
		simultaneous_rotations(a, b, push_a, push_b);
		individual_rotation_a(a, push_a);
		individual_rotation_b(b, push_b);
	}
}

void	push_swap(t_l *a, t_l *b)
{
	t_l	*push_a;
	t_l	*push_b;

	push_a = push_cost_total(a, b);
	push_b = push_a->target_node;
	execute_push_swap_loop(&a, &b, push_a, push_b);
}

void	actual_push_swap(t_l *a, t_l *b)
{
	while (stack_size(a) >= 3)
	{
		if (stack_size(a) > 3)
		{
			push_swap(a, b);
			pb(&b, &a);
		}
		if (stack_size(a) == 3)
		{
			three_elem_sort(&a);
			while (stack_size(b) > 0)
			{
				push_swap(b, a);
				pa(&b, &a);
			}
		}
		if (stack_size(b) == 0)
			break ;
	}
	if (stack_size(a) == 3 || is_sorted(a))
		printf("Sorted");
}

void	sizebased_operation(t_l *a, t_l *b)
{
	if (is_sorted(a))
		exit(0);
	if (stack_size(a) == 2)
		two_elem_sort(a);
	if (stack_size(a) == 3)
		three_elem_sort(&a);
	if (stack_size(a) > 3)
	{
		pb(&b, &a);
		if (stack_size(a) > 3)
			pb(&b, &a);
	}
	if (!is_sorted(a))
		actual_push_swap(a, b);
}

int	main(int ac, char **av)
{
	t_l	*a;
	t_l	*b;
	t_l	*ptr;
	int	i;

	i = 1;
	a = NULL;
	b = NULL;
	if (ac == 1)
		return (0);
	else if (ac == 2)
		ft_split(av, ' ', &a);
	else if (ac > 2)
		handle_input(av, ac, &a);
	ptr = a;
	// while (ptr)
	// {
	// 	printf("Element %d: %d\n", i, ptr->nbr);
	// 	ptr = ptr->next;
	// 	i++;
	// }
	sizebased_operation(a, b);
	free_list(a);
	return (0);
}
