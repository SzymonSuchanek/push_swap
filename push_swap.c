/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssuchane <ssuchane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 16:28:50 by ssuchane          #+#    #+#             */
/*   Updated: 2024/06/26 13:45:23 by ssuchane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	update_and_execute(t_l **a, t_l **b, t_l **to_push)
{
	update_indexes(a, b);
	update_targets(a, b);
	calculate_push_costs(a, b);
	*to_push = find_cheapest_node(b);
	update_median(a);
	update_median(b);
	execute_operations(a, b, *to_push);
	push_a(a, b);
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
			if (stack_size(*a) > 5 && *a == find_second_highest(*a))
				r(a, 'a');
			push_b(a, b);
		}
		else
		{
			three_elem_sort(a);
			while (stack_size(*b) > 0)
				update_and_execute(a, b, &to_push);
		}
		if (stack_size(*b) == 0)
			break ;
	}
	update_median(a);
	update_indexes(a, b);
	if (!is_sorted(*a))
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
	else if (argc >= 3)
		handle_input(argv, argc, &a);
	update_indexes(&a, &b);
	sizebased_operation(&a, &b);
	exit_free_list(a);
	return (0);
}
