/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhasanov <vhasanov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 23:43:21 by vhasanov          #+#    #+#             */
/*   Updated: 2025/06/13 01:44:10 by vhasanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"
#include <stdio.h>

int	*populate_stack_and_array(int size, char **argv, t_Stack *stack)
{
	int	i;
	int	*arr;

	arr = (int *)malloc(sizeof(int) * (size));
	if (arr == NULL)
		return (NULL);
	i = size;
	while (i > 0)
	{
		push(stack, ft_atoi(argv[i]), ' ');
		arr[i - 1] = ft_atoi(argv[i]);
		i--;
	}
	return (arr);
}

void	sort_based_on_size(int size, t_Stack *stack_a, t_Stack *stack_b,
		int *arr)
{
	if (size == 2)
	{
		if (stack_a->top->value > stack_a->top->next->value)
			ft_swap(stack_a, 'a');
	}
	else if (size == 3)
		sort_3(stack_a, 'a');
	else
	{
		quick_sort(arr, 0, size - 1);
		sort_stack_a(stack_a, stack_b, arr, size);
		sort_stack_b(stack_a, stack_b, arr, size);
	}
}

int	main(int argc, char **argv)
{
	int		*arr;
	t_Stack	stack_a;
	t_Stack	stack_b;

	if (argc < 2)
		return (1);
	init_stack(&stack_a);
	init_stack(&stack_b);
	if (invalid_num(argv))
		return (cleanup_and_return(NULL, &stack_a, &stack_b, 1));
	arr = populate_stack_and_array(argc - 1, argv, &stack_a);
	if (arr == NULL)
		return (cleanup_and_return(arr, &stack_a, &stack_b, 1));
	if (has_duplicates(arr, argc - 1))
		return (cleanup_and_return(arr, &stack_a, &stack_b, 1));
	if (is_sorted(arr, argc - 1))
		return (cleanup_and_return(arr, &stack_a, &stack_b, 0));
	sort_based_on_size(argc - 1, &stack_a, &stack_b, arr);
	return (cleanup_and_return(arr, &stack_a, &stack_b, 0));
}
