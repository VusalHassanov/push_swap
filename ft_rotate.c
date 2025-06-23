/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhasanov <vhasanov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 21:42:42 by vhasanov          #+#    #+#             */
/*   Updated: 2025/06/12 02:22:49 by vhasanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	rotate(t_Stack *stack, char c)
{
	t_Node	*old_top;

	if (stack->top == NULL || stack->top->next == NULL)
		return ;
	old_top = stack->top;
	stack->top = stack->top->next;
	stack->top->prev = NULL;
	stack->tail->next = old_top;
	old_top->prev = stack->tail;
	stack->tail = old_top;
	stack->tail->next = NULL;
	ft_printf("r%c\n", c);
}
