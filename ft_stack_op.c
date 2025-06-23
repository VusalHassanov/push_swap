/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_op.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhasanov <vhasanov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 02:17:08 by vhasanov          #+#    #+#             */
/*   Updated: 2025/06/13 01:53:13 by vhasanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	cal_chunk_size(int size)
{
	int	chunk_size;
	int	count;

	count = 5;
	if (size > 100)
		count = 10;
	chunk_size = size / count;
	if (chunk_size == 0)
		chunk_size = 1;
	return (chunk_size);
}

int	is_in_chunk(t_Stack *stack, int min, int max)
{
	t_Node	*current;

	if (!stack || !stack->top)
		return (0);
	current = stack->top;
	while (current)
	{
		if (current->value <= max && current->value >= min)
			return (1);
		current = current->next;
	}
	return (0);
}

void	stack_operation(t_Stack *stack_1, t_Stack *stack_2, int rotation_time,
		char *rotation_type)
{
	int	count;

	count = 0;
	while (count < rotation_time)
	{
		if (ft_strcmp(rotation_type, "ra") == 0)
			rotate(stack_1, 'a');
		else if (ft_strcmp(rotation_type, "rra") == 0)
			r_rotate(stack_1, 'a');
		else if (ft_strcmp(rotation_type, "rb") == 0)
			rotate(stack_1, 'b');
		else if (ft_strcmp(rotation_type, "rrb") == 0)
			r_rotate(stack_1, 'b');
		count++;
	}
	if (ft_strchr(rotation_type, 'a') != NULL)
	{
		push(stack_2, stack_1->top->value, 'b');
		pop(stack_1);
	}
	else if (ft_strchr(rotation_type, 'b') != NULL)
	{
		push(stack_2, stack_1->top->value, 'a');
		pop(stack_1);
	}
}

void	operation_choice(t_Stack *stack_a, t_Stack *stack_b, int op_count,
		int middle_value)
{
	if (op_count > 0)
		stack_operation(stack_a, stack_b, op_count, "ra");
	else
		stack_operation(stack_a, stack_b, (-1) * op_count, "rra");
	if (stack_b->top->value < middle_value)
		rotate(stack_b, 'b');
}
