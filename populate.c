/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   populate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssuchane <ssuchane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 15:43:49 by ssuchane          #+#    #+#             */
/*   Updated: 2024/05/19 17:16:19 by ssuchane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	populate_a(b_list **a, int n)
{
	b_list	*node;
	b_list	*last_node;

	node = malloc(sizeof(b_list));
	node->nbr = n;
	node->next = NULL;
	if (!a)
	{
		*a = node;
		node->prev = NULL;
	}
	else
	{
		last_node = find_last_in_list(*a);
		last_node->next = node;
		node->prev = last_node;
	}
}

b_list	*find_last_in_list(b_list *a)
{
	b_list	*ptr;

	if (!a)
		return (NULL);
	ptr = a;
	while (ptr->next)
		ptr = ptr->next;
	return (ptr);
}

