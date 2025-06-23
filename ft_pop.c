/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pop.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhasanov <vhasanov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 21:42:12 by vhasanov          #+#    #+#             */
/*   Updated: 2025/06/12 00:05:36 by vhasanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	pop(t_Stack *stack)
{
	t_Node	*temp;

	if (stack->top == NULL)
	{
		write(1, "Stack underflow !", 17);
		return ;
	}
	temp = stack->top;
	stack->top = stack->top->next;
	if (stack->top)
		stack->top->prev = NULL;
	else
		stack->tail = NULL;
	free(temp);
}
