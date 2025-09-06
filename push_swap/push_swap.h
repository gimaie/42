/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gimaie <gimaie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 12:04:44 by gimaie            #+#    #+#             */
/*   Updated: 2025/08/06 19:37:54 by gimaie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

# ifndef INT_MAX
#  define INT_MAX 2147483647
# endif

# ifndef INT_MIN
#  define INT_MIN -2147483648
# endif

typedef struct s_list
{
	int				content;
	struct s_list	*next;
	struct s_list	*prev;
}	t_list;

typedef struct s_stack
{
	t_list	*head;
	t_list	*bottom;
	int		size;
}	t_stack;

typedef struct s_move_cost
{
	int	ra_moves;
	int	rb_moves;
	int	rra_moves;
	int	rrb_moves;
	int	total_cost;
}	t_move_cost;

typedef struct s_calc_params
{
	int	idx_a;
	int	idx_b;
	int	size_a;
	int	size_b;
}	t_calc_params;

long		*clean_command(int argc, char **argv, int *out_count);
int			int_range(long *ns, int *count);
int			sorted(long *ns, int *count);
int			duplicated(long *ns, int *count);
int			numeric(int argc, char **argv);
int			is_valid_long_array(long *long_ns, int *count);
int			*create_ints(long *long_ns, int size);
int			*validate_args(int argc, char **argv);
void		simple_sort(int *arr, int size, int *ns);
int			index_numbers(int *ns, int size);
t_list		*create_last_node(t_list *head, int *ns, int size);
t_list		*make_list(int *ns, int size);
t_stack		*assign_stack(t_list *list_head, int size);
t_stack		*make_stack_a(int *ns, int size);
t_stack		*make_stack_b(t_stack *a);
void		ra(t_stack *a);
void		rb(t_stack *b);
void		rr(t_stack *a, t_stack *b);
void		rra(t_stack *a);
void		rrb(t_stack *b);
void		rrr(t_stack *a, t_stack *b);
void		sa(t_stack *a);
void		sb(t_stack *b);
void		ss(t_stack *a, t_stack *b);
void		pa(t_stack *b, t_stack *a);
void		pb(t_stack *a, t_stack *b);
void		swap(t_stack *stack);
void		push(t_stack *from, t_stack *to);
void		rotate(t_stack *stack);
void		reverse_rotate(t_stack *stack);
void		sort_stack(t_stack *a, t_stack *b);
void		sort_two(t_stack *stack);
void		sort_three(t_stack *stack);
void		sort_five(t_stack *a, t_stack *b, int n);
t_list		*get_min(t_list *head);
int			where_min(t_stack *a);
void		min_to_b(t_stack *a, t_stack *b, int i);
void		sort_turk(t_stack *a, t_stack *b);
int			find_insert_pos_in_b(t_stack *b, int value_from_a);
t_list		*get_min_node(t_stack *b);
t_list		*get_max_node(t_stack *b);
int			get_node_index(t_stack *stack, t_list *target_list);
t_move_cost	init_move_cost(void);
int			calc_rot_moves(int stack_size, int index, int type);
t_move_cost	calculate_cost_a_to_b(t_stack *a, t_stack *b,
				t_list *a_node_to_move);
t_move_cost	find_min_pattern_cost(t_calc_params *params);
void		calc_cost_p1(t_move_cost *cost_info, t_calc_params *params);
void		calc_cost_p2(t_move_cost *cost_info, t_calc_params *params);
void		calc_cost_p3(t_move_cost *cost_info, t_calc_params *params);
void		calc_cost_p4(t_move_cost *cost_info, t_calc_params *params);
void		execute_moves(t_stack *a, t_stack *b, t_move_cost smallest_cost);
void		execute_moves_each(t_stack *a, t_stack *b,
				t_move_cost smallest_cost);
void		push_all_to_b(t_stack *a, t_stack *b);
int			find_optimal_insert_pos_in_a(t_stack *a, int value_from_b);
void		push_all_to_a(t_stack *a, t_stack *b);
void		align_final_stack(t_stack *a);
t_list		*ft_lstnew_prev(int *content, t_list *prev);
long		ft_atol(const char *nptr);
void		ft_free_list(t_list *lst);
void		free_stack(t_stack *stack);
t_list		*ft_lst_head(int *content);
void		*ft_memset(void *s, int c, size_t n);

#endif
