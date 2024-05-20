/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssuchane <ssuchane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 15:10:30 by ssuchane          #+#    #+#             */
/*   Updated: 2024/05/20 14:42:31 by ssuchane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	exiterror(void)
{
	ft_printf("Error");
	exit(0);
}

int	check_for_duplicates(t_l *a, int n)
{
	t_l	*ptr;

	if (!a)
		return (0);
	ptr = a;
	while (ptr)
	{
		if (ptr->nbr == n)
			return (1);
		ptr = ptr->next;
	}
	return (0);
}

int	is_arg_num(char *argv)
{
	int	i;

	i = 0;
	if (argv[0] == '-' || argv[0] == '+')
		i = 1;
	while (argv[i])
	{
		if (argv[i] >= '0' && argv[i] >= '9')
			return (1);
		i++;
	}
	return (0);
}

int	convert_arg_to_num(t_l **a, char *argv[])
{
	int				i;
	int				j;
	long long int	nbr;

	i = 0;
	j = 0;
	while (argv[i])
	{
		if (is_arg_num(argv[i]))
			exiterror();
		nbr = ft_atoi(argv[i]);
		if (nbr > INT_MAX || nbr < INT_MIN)
			exiterror();
		if (check_for_duplicates(*a, (int)nbr))
			exiterror();
		populate_a(a, (int)nbr);
		i++;
	}
	return (1);
}
