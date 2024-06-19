/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssuchane <ssuchane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 17:50:20 by ssuchane          #+#    #+#             */
/*   Updated: 2024/06/19 18:36:13 by ssuchane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct a_list
{
	int				nbr;
	int				index;
	int				push_cost;
	int				median;
	int				cheapest;
	struct a_list	*target_node;
	struct a_list	*next;
	struct a_list	*prev;
}					t_l;

void				push_a(t_l **a, t_l **b);
void				push_b(t_l **a, t_l **b);
void				r(t_l **b, char which);
void				rr(t_l **a, t_l **b);
void				reverse_rotate(t_l **stack, char which);
void				rrr(t_l **a, t_l **b);
void				s(t_l **stack, char which);
void				ss(t_l **a, t_l **b);

void				update_indexes(t_l **a, t_l **b);
t_l					*find_last_node(t_l *a);

//	errors.c
void				free_list(t_l *list);
void				exit_free_list(t_l *list);
void				exit_error(void);
void				exit_error_free(t_l *stack);

//	utils_stack.c
t_l					*find_last_node(t_l *a);
void				populate_a(t_l **a, int n);
int					stack_size(t_l *a);
int					is_sorted(t_l *a);

//	utils_string.c
int					ft_atoi(char *str);
int					is_num(char c);
int					is_sign(char c);

//	handle_input.c
int					check_doubles(t_l *a, int n);
void				ft_split(char **argv, char c, t_l **a);
void				handle_input(char **argv, int argc, t_l **a);

//	update_variables.c
void				update_indexes(t_l **a, t_l **b);
void				update_targets(t_l **a, t_l **b);
void				update_median(t_l **stack);

//	low_sort.c
t_l					*find_highest(t_l *stack);
void				two_elem_sort(t_l *a);
void				three_elem_sort(t_l **a);

#endif
