/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zjamali <zjamali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 11:09:09 by zjamali           #+#    #+#             */
/*   Updated: 2021/07/13 18:45:06 by zjamali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_execute_instruction(t_vector *stack_a, t_vector *stack_b,
			char *instruction)
{
	if (ft_strncmp(instruction, "pb", ft_strlen(instruction)) == 0)
		ft_push(stack_a, stack_b);
	else if (ft_strncmp(instruction, "pa", ft_strlen(instruction)) == 0)
		ft_push(stack_b, stack_a);
	else if (ft_strncmp(instruction, "sa", ft_strlen(instruction)) == 0)
		ft_swap(stack_a);
	else if (ft_strncmp(instruction, "sb", ft_strlen(instruction)) == 0)
		ft_swap(stack_b);
	else if (ft_strncmp(instruction, "ss", ft_strlen(instruction)) == 0)
		ft_swap_both_stacks(stack_a, stack_b);
	else if (ft_strncmp(instruction, "ra", ft_strlen(instruction)) == 0)
		ft_rotate(stack_a);
	else if (ft_strncmp(instruction, "rb", ft_strlen(instruction)) == 0)
		ft_rotate(stack_b);
	else if (ft_strncmp(instruction, "rr", ft_strlen(instruction)) == 0)
		ft_rotate_both_stacks(stack_a, stack_b);
	else if (ft_strncmp(instruction, "rra", ft_strlen(instruction)) == 0)
		ft_reverse_rotate(stack_a);
	else if (ft_strncmp(instruction, "rrb", ft_strlen(instruction)) == 0)
		ft_reverse_rotate(stack_b);
	else if (ft_strncmp(instruction, "rrr", ft_strlen(instruction)) == 0)
		ft_reverse_rotate_both_stacks(stack_a, stack_b);
	else
		ft_display_error_and_exit();
}

void	checker(char **data)
{
	t_vector	stack_a;
	t_vector	stack_b;
	char		*instruction;

	instruction = NULL;
	ft_vector_init(&stack_a, sizeof(int));
	ft_vector_init(&stack_b, sizeof(int));
	ft_push_to_data_stack(&stack_a, data);
	if (stack_a.used >= 1)
	{
		while (get_next_line(&instruction))
		{
			if (instruction[0] == '\0')
				ft_display_error_and_exit();
			ft_execute_instruction(&stack_a, &stack_b, instruction);
			free(instruction);
			instruction = NULL;
		}
		if ((stack_b.used == 0) && (ft_check_data_is_sorted(stack_a) == 0))
			ft_putstr_fd("OK\n", 1);
		else
			ft_putstr_fd("KO\n", 1);
	}
	stack_a.vector_free(&stack_a);
	stack_a.vector_free(&stack_b);
}

int	main(int ac, char **av)
{
	char	**data;

	data = parse_arguments(av, ac);
	if (ft_check_data(data))
	{
		checker(data);
	}
	ft_free_data(data);
	return (0);
}
