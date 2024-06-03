/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssuchane <ssuchane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 18:45:43 by ssuchane          #+#    #+#             */
/*   Updated: 2024/06/03 19:33:52 by ssuchane         ###   ########.fr       */
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
		tab = list->next;
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

int	is_sorted(t_l **a)
{
	t_l	*node;

	node = *a;
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
int	stack_size(t_l **stack)
{
	int	count;
	t_l	*current;

	count = 0;
	current = *stack;
	while (current)
	{
		count++;
		current = current->next;
	}
	return (count);
}

void	two_elem_sort(t_l **a)
{
	t_l	*first;
	t_l	*second;

	first = *a;
	second = first->next;
	if (stack_size(a) == 1)
		exit(0);
	if (stack_size(a) == 2)
	{
		if (first->nbr > second->nbr)
			ra(a);
	}
	exit(0);
}

void	three_elem_sort(t_l **a)
{
	t_l	*first;
	t_l	*second;
	t_l	*third;

	first = *a;
	second = first->next;
	third = second->next;
	if (first->nbr < third->nbr && third->nbr < second->nbr)
	{
		rra(a);
		sa(a);
	}
	if (second->nbr < first->nbr && first->nbr < third->nbr)
		sa(a);
	if (second->nbr < third->nbr && third->nbr < first->nbr)
		rra(a);
	if (third->nbr < first->nbr && first->nbr < second->nbr)
		ra(a);
	if (third->nbr < second->nbr && second->nbr < first->nbr)
	{
		ra(a);
		sa(a);
	}
}

t_l	*find_closest_node(t_l *a_node, t_l *b_head)
{
	t_l	*closest;
	int	min_diff;
	t_l	*b_node;
	int	diff;

	closest = NULL;
	min_diff = INT_MAX;
	b_node = b_head;
	while (b_node != NULL)
	{
		diff = b_node->nbr - a_node->nbr;
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

void	update_target_node(t_l **a_head, t_l **b_head)
{
	t_l	*a_node;
	t_l	*closest;
	t_l	*max_node;

	a_node = *a_head;
	while (a_node != NULL)
	{
		closest = find_closest_node(a_node, *b_head);
		if (closest != NULL)
			a_node->target_node = closest;
		else
		{
			max_node = find_max_node(*b_head);
			a_node->target_node = max_node;
		}
		a_node = a_node->next;
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
	total_nodes = 0;
	while (current != NULL)
	{
		total_nodes++;
		current = current->next;
	}
	current = *stack;
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

// iterate through each node of stack a and it's target_node, then
// calculate and update push_cost based on median and index of both 
// node a and it's target_node in stack b

void	push_cost_total(t_l **a, t_l **b)
{
	t_l	*current;
	t_l	*target_node;
	int	push_cost;

	update_index(b);
	update_median(b);
	update_index(a);
	update_median(a);
	update_target_node(a, b);
	current = *a;
	while (current != NULL)
	{
		target_node = current->target_node;
		if ((current->median == 1 && target_node->median == -1)
			|| (current->median == -1 && target_node->median == -1))
			push_cost = current->index + target_node->index;
		else
		{
			if (current->index > target_node->index)
				push_cost = current->index;
			else
				push_cost = target_node->index;
		}
	}
}

void	push_swap(t_l **a, t_l **b)
{
	// calculate total push cost for values in stack a and stack b
	// find the cheapest push cost
	// execute the operations for the cheapest variables (print operations
	//	+ execute operations)
	// check if the stack is sorted
}

void	sizebased_operation(t_l **a, t_l **b)
{
	if (is_sorted(a))
		exit(0);
	if (stack_size(a) == 2)
		two_elem_sort(a);
	if (stack_size(a) == 3)
		three_elem_sort(a);
	if (stack_size(a) > 3)
	{
		pb(a);
		if (stack_size(a) > 3)
			pb(a);
	}
	push_swap(a, b);
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
	while (ptr)
	{
		printf("Element %d: %d\n", i, ptr->nbr);
		ptr = ptr->next;
		i++;
	}
	sizebased_operation(a, b);
	push_swap(a, b);
	free_list(a);
	return (0);
}

// break down split to pass norminette
// figure out the logic for when operation on both stacks are simultanous
