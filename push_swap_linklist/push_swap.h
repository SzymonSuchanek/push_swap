/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssuchane <ssuchane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 15:02:42 by ssuchane          #+#    #+#             */
/*   Updated: 2024/05/20 13:49:33 by ssuchane         ###   ########.fr       */
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
}					t_l;

void	exiterror(void);
int		check_for_duplicates(t_l *a, int n);
int		is_arg_num(char *argv);
t_l		*find_last_node(t_l *a);
void	populate_a(t_l **a, int n);
int		convert_arg_to_num(t_l **a, char *argv[]);

#endif