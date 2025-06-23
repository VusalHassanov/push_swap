/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhasanov <vhasanov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 21:42:31 by vhasanov          #+#    #+#             */
/*   Updated: 2025/06/12 00:06:06 by vhasanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	push(t_Stack *stack, int value, char c)
{
	t_Node	*new_node;

	new_node = (t_Node *)malloc(sizeof(t_Node));
	if (new_node == NULL)
	{
		ft_printf("Memory allocation failed\n");
		return ;
	}
	new_node->value = value;
	new_node->prev = NULL;
	new_node->next = stack->top;
	if (stack->top)
		stack->top->prev = new_node;
	else
		stack->tail = new_node;
	stack->top = new_node;
	if (c != ' ')
		ft_printf("p%c\n", c);
}
