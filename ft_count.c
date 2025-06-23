/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhasanov <vhasanov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 18:32:13 by vhasanov          #+#    #+#             */
/*   Updated: 2025/06/12 00:07:15 by vhasanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	top_target(t_Stack *stack, int min, int max)
{
	t_Node	*current;
	int		count;
	int		stack_size;

	stack_size = count_stack(stack);
	current = stack->top;
	count = 0;
	while (current)
	{
		if (current->value <= max && current->value >= min)
			break ;
		current = current->next;
		count++;
	}
	if (count > stack_size / 2)
		return (count - stack_size);
	return (count);
}

int	count_stack(t_Stack *stack)
{
	t_Node	*current;
	int		count;

	count = 0;
	current = stack->top;
	while (current)
	{
		current = current->next;
		count++;
	}
	return (count);
}
