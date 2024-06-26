/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssuchane <ssuchane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 16:07:28 by eaktimur          #+#    #+#             */
/*   Updated: 2024/06/26 13:36:18 by ssuchane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>

typedef struct a_list
{
	int				nbr;
	int				index;
	int				push_cost;
	int				median;
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

// algorithm
void				calculate_push_costs(t_l **a_node, t_l **b_node);
t_l					*find_cheapest_node(t_l **b_node);
void				execute_operations1(t_l **a, t_l **b, t_l *to_push,
						t_l *target);
void				execute_operations(t_l **a, t_l **b, t_l *to_push);
void				final_rotate(t_l **a);

// errors
void				exit_free_list(t_l *list);
void				exit_error(void);
void				exit_error_free(t_l *stack);
void				free_list(t_l *list);

// ft_split
int					check_doubles(t_l *a, int n);
void				populate1(int *num_and_flags, t_l **a_list);
void				populate_split(char *str, char c, int *num_and_flags,
						t_l **a_list);

void				ft_split(char **argv, char c, t_l **a);

//	handle_input
void				handle_input(char **argv, int argc, t_l **a);
int					stack_size(t_l *a);
t_l					*find_highest(t_l *head);
t_l					*find_second_highest(t_l *head);

// push_swap
void				update_and_execute(t_l **a, t_l **b, t_l **to_push);
void				actual_push_swap(t_l **a, t_l **b);
void				sizebased_operation(t_l **a, t_l **b);
int					main(int argc, char **argv);

// setup
t_l					*find_last_node(t_l *a);
void				populate_a(t_l **a, int n);
int					ft_atoi(char *str);
int					is_num(char c);
int					is_sign(char c);

//	sort
int					is_sorted(t_l *a);
void				two_elem_sort(t_l *a);
void				three_elem_sort(t_l **a);

//	update
void				update_indexes(t_l **a, t_l **b);
void				update_targets(t_l **a, t_l **b);
void				update_median(t_l **stack);

#endif
