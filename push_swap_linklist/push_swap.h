/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssuchane <ssuchane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 18:46:58 by ssuchane          #+#    #+#             */
/*   Updated: 2024/06/06 21:40:11 by ssuchane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdio.h>
# include <stdlib.h>

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

void				sa(t_l **stack);
void				sb(t_l **stack);
void				ss(t_l **a, t_l **b);
void				pa(t_l **b, t_l **a);
void				pb(t_l **a, t_l **b);
void				ra(t_l **a);
void				rb(t_l **b);
void				rr(t_l **a, t_l **b);
void				rra(t_l **stack);
void				rrb(t_l **stack);
void				rrr(t_l **a, t_l **b);

void				exit_error(void);
void				exit_error_free(t_l *stack);
void				free_list(t_l *list);
t_l					*find_last_node(t_l *a);
void				populate_a(t_l **a, int n);
int					ft_atoi(char *str);
int					is_num(char c);
int					is_sign(char c);
int					check_doubles(t_l *a, int n);
void				ft_split(char **argv, char c, t_l **a);
void				handle_input(char **av, int ac, t_l **a);
int					is_sorted(t_l *a);
int					stack_size(t_l *stack);
void				two_elem_sort(t_l *a);
void				three_elem_sort(t_l *a);
t_l					*find_closest_node(t_l *a_node, t_l *b_head);
t_l					*find_max_node(t_l *b_head);
void				update_target_node(t_l **a_head, t_l **b_head);
void				update_index(t_l *stack);
void				update_median(t_l *stack);
void				update_variables(t_l *a, t_l *b);
t_l					*find_min_push_cost(t_l *a, t_l *b, t_l **min_node);
t_l					*find_min_push_cost(t_l *a, t_l *b, t_l **min_node);
int					get_push_cost(t_l *current, t_l *b);
t_l					*push_cost_total(t_l *a, t_l *b);
void				actual_push_swap(t_l *a, t_l *b);
void				simultaneous_rotations(t_l **a, t_l **b, t_l *push_a,
						t_l *push_b);
void				individual_rotation_a(t_l **a, t_l *push_a);
void				individual_rotation_b(t_l **b, t_l *push_b);
void				execute_push_swap_loop(t_l **a, t_l **b, t_l *push_a,
						t_l *push_b);
void				push_swap(t_l *a, t_l *b);
void				sizebased_operation(t_l *a, t_l *b);

#endif