/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhasanov <vhasanov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 21:25:04 by vhasanov          #+#    #+#             */
/*   Updated: 2025/06/12 00:08:04 by vhasanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	sort_3(t_Stack *stack, char ch)
{
	int	a;
	int	b;
	int	c;

	a = stack->top->value;
	b = stack->top->next->value;
	c = stack->top->next->next->value;
	if (a > b && b < c && a < c)
		ft_swap(stack, ch);
	else if (a > b && b > c)
	{
		ft_swap(stack, ch);
		r_rotate(stack, ch);
	}
	else if (a > b && b < c && a > c)
		rotate(stack, ch);
	else if (a < b && b > c && a < c)
	{
		ft_swap(stack, ch);
		rotate(stack, ch);
	}
	else if (a < b && b > c && a > c)
		r_rotate(stack, ch);
}
