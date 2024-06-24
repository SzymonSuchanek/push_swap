/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssuchane <ssuchane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 16:59:46 by eaktimur          #+#    #+#             */
/*   Updated: 2024/06/24 16:33:31 by ssuchane         ###   ########.fr       */
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
