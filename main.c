/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssuchane <ssuchane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 15:02:13 by ssuchane          #+#    #+#             */
/*   Updated: 2024/05/20 15:09:56 by ssuchane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_l		*a;
	t_l		*b;
	t_l		*temp;
	int		i;
	char	**argv_split;

	i = 0;
	a = NULL;
	b = NULL;
	if (argc == 1)
		return (0);
	if (argc == 2)
	{
		argv_split = ft_split(argv[1], ' ');
		convert_arg_to_num(&a, argv_split);
	}
	else if (argc > 2)
	{
		convert_arg_to_num(&a, (argv + 1));
	}
	while (a)
	{
		temp = a;
		ft_printf("Argument %d: %d\n", i, a->nbr);
		a = temp->next;
	}
	return (0);
}
