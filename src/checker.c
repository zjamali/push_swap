/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zjamali <zjamali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 11:09:09 by zjamali           #+#    #+#             */
/*   Updated: 2021/07/08 13:27:23 by zjamali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "gnl/get_next_line.h"
void	checker(char **data)
{
	t_vector	stack_a;
	t_vector	stack_b;
	char		**instruction;

	instruction = NULL;
	ft_vector_init(&stack_a, sizeof(int));
	ft_vector_init(&stack_b, sizeof(int));
	ft_push_to_data_stack(&stack_a, data);
	if (stack_a.used > 1 && ft_check_data_is_sorted(stack_a))
	{
		//get_next_line(0, instruction);
	//	while (get_next_line(0, instruction) > 0)
	//	{
	//		ft_putstr_fd("instruction : ", 1);
	//		ft_putstr_fd(*instruction, 1);
	//		ft_putstr_fd("\n", 1);
	//	}
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
