/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initialize.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhasanov <vhasanov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 21:41:56 by vhasanov          #+#    #+#             */
/*   Updated: 2025/06/12 11:54:05 by vhasanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	free_stack(t_Stack *stack)
{
	t_Node	*current;
	t_Node	*temp;

	if (stack->top != NULL)
	{
		current = stack->top;
		while (current != NULL)
		{
			temp = current;
			current = current->next;
			free(temp);
		}
	}
	stack->top = NULL;
	stack->tail = NULL;
}
