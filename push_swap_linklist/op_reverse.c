/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_push copy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssuchane <ssuchane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 17:54:28 by ssuchane          #+#    #+#             */
/*   Updated: 2024/06/19 17:56:09 by ssuchane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	r(t_l **b, char which)
{
	t_l	*last;

	if (!*b || !(*b)->next)
		return ;
	last = find_last_node(*b);
	last->next = *b;
	*b = (*b)->next;
	(*b)->prev = NULL;
	last->next->prev = last;
	last->next->next = NULL;
	if (which == 'a')
		write(1, "ra\n", 3);
	else if (which == 'b')
		write(1, "rb\n", 3);
	update_indexes(NULL, b);
}

void	rr(t_l **a, t_l **b)
{
	r(a, 'x');
	r(b, 'x');
	write(1, "rr\n", 3);
}
