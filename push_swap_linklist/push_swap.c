/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssuchane <ssuchane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 18:45:43 by ssuchane          #+#    #+#             */
/*   Updated: 2024/06/12 15:03:28 by ssuchane         ###   ########.fr       */
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

int	is_sorted(t_l *head)
{
	t_l	*current;

	current = head;
	if (current == NULL || current->next == NULL)
		return (1);
	while (current->next != NULL)
	{
		if (current->nbr > current->next->nbr)
		{
			return (0);
		}
		current = current->next;
	}
	return (1);
}

int	stack_size(t_l *head)
{
	int	count;
	t_l	*current;

	count = 0;
	current = head;
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

t_l	*find_closest_node(t_l *head_a, t_l *head_b)
{
	t_l	*node_b;
	t_l	*closest;

	closest = NULL;
	node_b = head_b;
	while (node_b != NULL)
	{
		if (node_b->nbr < head_a->nbr)
		{
			if (closest == NULL || node_b->nbr > closest->nbr)
			{
				closest = node_b;
			}
		}
		node_b = node_b->next;
	}
	return (closest);
}

t_l	*find_max_node(t_l *head)
{
	t_l	*max_node;
	t_l	*current;

	max_node = NULL;
	current = head;
	while (current != NULL)
	{
		if (max_node == NULL || current->nbr > max_node->nbr)
			max_node = current;
		current = current->next;
	}
	return (max_node);
}

void	update_target_node(t_l *head_a, t_l *head_b)
{
	t_l	*current;
	t_l	*closest;
	t_l	*max_node;

	current = head_a;
	while (current != NULL)
	{
		closest = find_closest_node(current, head_b);
		if (closest != NULL)
			current->target_node = closest;
		else
		{
			max_node = find_max_node(head_b);
			current->target_node = max_node;
		}
		current = current->next;
	}
}

void	update_index(t_l *head)
{
	t_l	*current;
	int	index;

	current = head;
	index = 0;
	while (current != NULL)
	{
		current->index = index;
		current = current->next;
		index++;
	}
}

void	update_median(t_l *head)
{
	t_l	*current;
	int	total_nodes;
	int	index;
	int	mid;

	current = head;
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

void	update_variables(t_l *head_a, t_l *head_b)
{
	if (stack_size(head_a) > 0)
	{
		update_index(head_a);
		update_median(head_a);
	}
	if (stack_size(head_b) > 0)
	{
		update_index(head_b);
		update_median(head_b);
	}
	if (stack_size(head_a) > 0 && stack_size(head_b) > 0)
		update_target_node(head_a, head_b);
}

int	get_push_cost(t_l *current, t_l *head_a, t_l *head_b)
{
	t_l	*target_node;
	t_l	*temp;

	temp = current;
	target_node = current->target_node;
	if (current->median == -1)
		current->push_cost = stack_size(head_a) - current->index;
	else
		current->push_cost = current->index;
	temp = target_node;
	if (target_node->median == -1)
		target_node->push_cost = stack_size(head_b) - target_node->index;
	else
		target_node->push_cost = target_node->index;
	return (current->push_cost + target_node->push_cost);
}

t_l	*find_min_push_cost(t_l *head_a, t_l *head_b, t_l **min_node)
{
	t_l	*current;
	int	min_cost;
	int	push_cost;

	min_cost = INT_MAX;
	current = head_a;
	if (current == NULL)
	{
		*min_node = NULL;
		return (NULL);
	}
	while (current != NULL)
	{
		push_cost = get_push_cost(current, head_a, head_b);
		if (push_cost < min_cost)
		{
			min_cost = push_cost;
			*min_node = current;
			if (min_cost == 0)
				return (*min_node);
		}
		current = current->next;
	}
	return (*min_node);
}

t_l	*push_cost_total(t_l *head_a, t_l *head_b)
{
	t_l	*min_node;

	update_variables(head_a, head_b);
	min_node = NULL;
	find_min_push_cost(head_a, head_b, &min_node);
	return (min_node);
}

void	simultaneous_rotations(t_l **a, t_l **b, t_l *push_a, t_l *push_b)
{
	if (push_a->median >= 0	&& push_b->median >= 0)
		rrr(a, b);
	else if (push_a->median == -1)
		rr(a, b);
}

void	individual_rotation_a(t_l **a, t_l *push_a)
{
	if (push_a->median == 1 || push_a->median == 0)
		ra(a);
	else if (push_a->median == -1)
		rra(a);
}

void	individual_rotation_b(t_l **b, t_l *push_b)
{
	if (push_b->median == 1 || push_b->median == 0)
		rb(b);
	else if (push_b->median == -1)
		rrb(b);
}

void	execute_push_swap_loop(t_l **a, t_l **b, t_l *push_a, t_l *push_b)
{
	while (push_a->index != 0 || push_b->index != 0)
	{
		if (push_a->index > 0 && push_b->index > 0)
		{
			simultaneous_rotations(a, b, push_a, push_b);
			push_a->index--;
			push_b->index--;
		}
		if (push_a->index > 0)
		{
			individual_rotation_a(a, push_a);
			push_a->index--;	
		}
		if (push_b->index > 0)
		{
			individual_rotation_b(b, push_b);
			push_b->index--;
		}
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
			printf("Before\n");
			t_l *aa = a;
			while (aa)
			{
				printf("%d ", aa->nbr);
				aa = aa->next;
			}
			printf("\n");
			push_swap(a, b);
			pb(&b, &a);
			printf("After\n");
			aa = a;
			while (aa)
			{
				printf("%d ", aa->nbr);
				aa = aa->next;
			}
			printf("\n");
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
		printf("stack size a:%d\n", stack_size(a));
		printf("stack size b:%d\n", stack_size(b));
		if (stack_size(b) == 0)
			break ;
	}
	if (stack_size(b) == 0 && is_sorted(a))
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
