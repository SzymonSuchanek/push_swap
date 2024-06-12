/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssuchane <ssuchane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 14:08:29 by ssuchane          #+#    #+#             */
/*   Updated: 2024/06/12 19:28:04 by ssuchane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_l **b, t_l **a)
{
	t_l	*node_to_move;

	if (!b || !*b)
		return ;
	node_to_move = *b;
	*b = node_to_move->next;
	if (*b)
		(*b)->prev = NULL;
	node_to_move->next = *a;
	if (*a)
		(*a)->prev = node_to_move;
	node_to_move->prev = NULL;
	*a = node_to_move;
	// update to ft_printf
	printf("pa\n");
}

void	pb(t_l **a, t_l **b)
{
	t_l	*node_to_move;

	if (!b || !*b)
		return ;
	node_to_move = *b;
	*b = node_to_move->next;
	if (*b)
		(*b)->prev = NULL;
	node_to_move->next = *a;
	if (*a)
		(*a)->prev = node_to_move;
	node_to_move->prev = NULL;
	*a = node_to_move;
	// update to ft_printf
	printf("pb\n");
}
