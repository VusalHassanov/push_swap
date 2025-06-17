/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhasanov <vhasanov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 21:42:25 by vhasanov          #+#    #+#             */
/*   Updated: 2025/06/13 19:38:08 by vhasanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUSH_SWAP_H
# define FT_PUSH_SWAP_H

# include "lib_ft/libft.h"
# include <limits.h>

typedef struct t_Node
{
	int				value;
	struct t_Node	*next;
	struct t_Node	*prev;
}					t_Node;

typedef struct t_Stack
{
	t_Node			*top;
	t_Node			*tail;
	int				size;
}					t_Stack;

int					top_target(t_Stack *stack, int min, int max);
void				init_stack(t_Stack *stack);
int					count_stack(t_Stack *stack);
void				init_stack(t_Stack *stack);
int					is_empty(t_Stack *stack);
void				pop(t_Stack *stack);
void				sort_stack_a(t_Stack *stack_a, t_Stack *stack_b, int *arr,
						int total);
void				sort_stack_b(t_Stack *stack_a, t_Stack *stack_b, int *arr,
						int total);
void				push(t_Stack *stack, int value, char c);
void				quick_sort(int *arr, int first, int last);
void				rotate(t_Stack *stack, char c);
void				r_rotate(t_Stack *stack, char c);
void				ft_swap(t_Stack *stack, char c);
void				sort_3(t_Stack *stack, char ch);
int					cal_chunk_size(int size);
int					is_in_chunk(t_Stack *stack, int min, int max);
void				stack_operation(t_Stack *stack_1, t_Stack *stack_2,
						int rotation_time, char *rotation_type);
void				operation_choice(t_Stack *stack_a, t_Stack *stack_b,
						int op_count, int middle_value);
void				free_stack(t_Stack *stack);
int					is_sorted(int *arr, int size);
int					has_duplicates(int *arr, int size);
int					invalid_num(char **argv);
int					cleanup_and_return(int *arr, t_Stack *stack_a,
						t_Stack *stack_b, int exit_code);

#endif