/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_r_rotate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhasanov <vhasanov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 21:42:37 by vhasanov          #+#    #+#             */
/*   Updated: 2025/05/08 16:44:18 by vhasanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	r_rotate(t_Stack *stack, char c)
{
	t_Node	*new_top;
	t_Node	*new_end;

	if (stack->top == NULL || stack->tail == NULL)
		return ;
	new_top = stack->tail;
	new_end = stack->tail->prev;
	new_top->next = stack->top;
	stack->top->prev = new_top;
	stack->top = new_top;
	stack->tail = new_end;
	stack->top->prev = NULL;
	stack->tail->next = NULL;
	ft_printf("rr%c\n", c);
}
