/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssuchane <ssuchane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 15:02:42 by ssuchane          #+#    #+#             */
/*   Updated: 2024/05/19 17:15:21 by ssuchane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/headers/ft_printf.h"
# include "libft/headers/libft.h"
# include <limits.h>

typedef struct a_list
{
	int				nbr;
	struct a_list	*next;
	struct a_list	*prev;
}					b_list;

#endif