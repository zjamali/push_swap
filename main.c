/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zjamali <zjamali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 20:21:59 by zjamali           #+#    #+#             */
/*   Updated: 2021/06/16 21:54:12 by zjamali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
// memcpy(v.items, &(int[1]){5}, 4);

void	ft_init_stacks(t_stack *stacks)
{
	ft_vector_init(&stacks->a,sizeof(int));
	ft_vector_init(&stacks->b,sizeof(int));
}

int	main(int ac, char **av)
{
	t_stack stacks;

	ft_init_stacks(&stacks);
	return (0);
}
