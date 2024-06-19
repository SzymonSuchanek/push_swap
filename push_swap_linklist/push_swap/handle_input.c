/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssuchane <ssuchane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 18:28:27 by ssuchane          #+#    #+#             */
/*   Updated: 2024/06/19 18:30:00 by ssuchane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	int		is_negative;

	a_list = NULL;
	num = 0;
	is_num_started = 0;
	is_negative = 0;
	str = argv[1];
	while (*str)
	{
		if (*str == c)
		{
			if (is_num_started)
			{
				if (is_negative)
					num = -num;
				if (check_doubles(a_list, num))
					exit_error();
				populate_a(&a_list, num);
				is_num_started = 0;
				is_negative = 0;
			}
		}
		else if (is_num(*str) || (*str == '-' && !is_num_started))
		{
			if (!is_num_started)
			{
				is_num_started = 1;
				num = 0;
				if (*str == '-')
				{
					is_negative = 1;
					str++;
					continue ;
				}
			}
			num = num * 10 + (*str - '0');
		}
		else
			exit_error();
		str++;
	}
	if (is_num_started)
	{
		if (is_negative)
			num = -num;
		if (check_doubles(a_list, num))
			exit_error();
		populate_a(&a_list, num);
	}
	*a = a_list;
}

void	handle_input(char **argv, int argc, t_l **a)
{
	int i;
	int j;

	i = 1;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
		{
			if (!is_num(argv[i][j]) && !is_sign(argv[i][j]))
				exit_error();
			j++;
		}
		if (check_doubles(*a, ft_atoi(argv[i])))
			exit_error();
		populate_a(a, ft_atoi(argv[i]));
		i++;
	}
}
