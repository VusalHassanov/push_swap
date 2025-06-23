/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhasanov <vhasanov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 21:42:20 by vhasanov          #+#    #+#             */
/*   Updated: 2025/06/13 01:41:49 by vhasanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	sort_stack_a(t_Stack *stack_a, t_Stack *stack_b, int *arr, int total)
{
	int	max_index;
	int	middle_value;
	int	min_index;
	int	chunk_size;
	int	op_count;

	chunk_size = cal_chunk_size(total);
	max_index = -1;
	while (max_index < total - 4)
	{
		max_index = max_index + chunk_size;
		if (max_index > total - 4)
			max_index = total - 4;
		min_index = max_index - chunk_size;
		if (min_index < 0)
			min_index = 0;
		middle_value = arr[min_index + (max_index - min_index) / 3];
		while (is_in_chunk(stack_a, arr[min_index], arr[max_index]))
		{
			op_count = top_target(stack_a, arr[min_index], arr[max_index]);
			operation_choice(stack_a, stack_b, op_count, middle_value);
		}
	}
	sort_3(stack_a, 'a');
}

void	sort_stack_b(t_Stack *stack_a, t_Stack *stack_b, int *arr, int total)
{
	int	j;
	int	count;
	int	max;

	if (!stack_a || !stack_b || !arr || total <= 0)
		return ;
	j = total - 4;
	while (j >= 0 && stack_b->top)
	{
		max = arr[j];
		count = top_target(stack_b, max, max);
		if (count > 0)
			stack_operation(stack_b, stack_a, count, "rb");
		else
			stack_operation(stack_b, stack_a, (-1) * count, "rrb");
		j--;
	}
}
