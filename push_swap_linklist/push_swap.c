/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssuchane <ssuchane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 18:45:43 by ssuchane          #+#    #+#             */
/*   Updated: 2024/05/31 21:00:18 by ssuchane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	exit_error(void)
{
	printf("Error\n");
	exit(0);
}

void	exit_error_free(t_l *tab)
{
	t_l	*tmp;

	printf("Error\n");
	while (tab)
	{
		tmp = tab;
		tab = tab->next;
		free(tmp);
	}
	exit(0);
}

void	free_list(t_l *tab)
{
	t_l	*tmp;

	while (tab)
	{
		tmp = tab;
		tab = tab->next;
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

int	main(int ac, char **av)
{
	t_l *a;
	t_l *b;
	t_l *ptr;
	int i;

	i = 1;
	a = NULL;
	b = NULL;
	if (ac == 1)
		return (0);
	else if (ac == 2)
	{
		ft_split(av, ' ', &a);
		ptr = a;
		while (ptr)
		{
			printf("Element %d: %d\n", i, ptr->nbr);
			ptr = ptr->next;
			i++;
		}
	}
	else if (ac > 2)
	{
		handle_input(av, ac, &a);
		ptr = a;
		while (ptr)
		{
			printf("Element %d: %d\n", i, ptr->nbr);
			ptr = ptr->next;
			i++;
		}
	}
	//introduce sorting for 2, 3 & >3
	free_list(a);
	return (0);
}


// create sorting functions
// break down split into more functions for norminette
// create basic, fixed sort for 2 elements
// create sort for 3 elements
// -1 2 3 (is_sorted)
// -1 3 2
// -2 1 3
// -2 3 1
// -3 1 2
// -3 2 1
// push 2 elements from stack a to stack b if more than 3 elements in stack a

// in structure introduce and undestand following elements 
// -int index
// -push_cost
// -above_median
// -cheapest
// -*target_node