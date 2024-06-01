/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssuchane <ssuchane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 18:46:58 by ssuchane          #+#    #+#             */
/*   Updated: 2024/06/01 13:31:21 by ssuchane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdio.h>
# include <limits.h>

typedef struct a_list
{
	int				nbr;
	int				index;
	int				push_cost;
	int				above_median;
	int				cheapest;
	int				*target_node;
	struct a_list	*next;
	struct a_list	*prev;
}					t_l;

#endif