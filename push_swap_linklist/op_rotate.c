/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssuchane <ssuchane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 14:08:29 by ssuchane          #+#    #+#             */
/*   Updated: 2024/06/01 14:28:57 by ssuchane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_l **a)
{
	t_l	*first;
	t_l	*last;

	if (!a || !*a || !(*a)->next)
		return ;
	first = *a;
	last = *a;
	first = *a;
	last = *a;
	while (last->next)
		last = last->next;
	*a = first->next;
	(*a)->prev = NULL;
	first->next = NULL;
	first->prev = last;
	last->next = first;
	// update to ft_printf
	printf("ra\n");
}

void	rb(t_l **b)
{
	t_l	*first;
	t_l	*last;

	if (!b || !*b || !(*b)->next)
		return ;
	first = *b;
	last = *b;
	first = *b;
	last = *b;
	while (last->next)
		last = last->next;
	*b = first->next;
	(*b)->prev = NULL;
	first->next = NULL;
	first->prev = last;
	last->next = first;
	// update to ft_printf
	printf("ra\n");
}

void	rr(t_l **a, t_l **b)
{
	ra(a);
	rb(b);
}
