/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhasanov <vhasanov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 14:25:50 by vhasanov          #+#    #+#             */
/*   Updated: 2025/06/11 14:22:13 by vhasanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	ft_swap(t_Stack *stack, char c)
{
	t_Node	*old_top;

	if (!stack->top || !stack->top->next)
		return ;
	old_top = stack->top;
	stack->top = old_top->next;
	old_top->next = old_top->next->next;
	stack->top->next = old_top;
	ft_printf("s%c\n", c);
}
