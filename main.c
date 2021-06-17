/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zjamali <zjamali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 20:21:59 by zjamali           #+#    #+#             */
/*   Updated: 2021/06/17 15:28:47 by zjamali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	ft_init_stacks(t_stack *stacks)
{
	ft_vector_init(&stacks->a, sizeof(int));
	ft_vector_init(&stacks->b, sizeof(int));
}

char	**parse_arguments(char **av, int ac)
{
	char	**data;
	char	*line;
	int		i;
	char	*tmp;

	i = 1;
	line = ft_strdup("");
	data = NULL;
	while (i < ac)
	{
		tmp = line;
		line = ft_strjoin(line, av[i]);
		free(tmp);
		tmp = line;
		line = ft_strjoin(line," ");
		free(tmp);
		i++;
	}
	data = ft_split(line,' ');
	free(line);
	return (data);
}

int	main(int ac, char **av)
{
	char	**data;
//	t_stack	stacks;
	//ft_init_stacks(&stacks);
	data = parse_arguments(av, ac);
	for (int i = 0 ;  data[i] != NULL ; i++)
	{
		ft_putstr_fd(data[i],1);
		ft_putstr_fd("\n",1);
	}
	return (0);
}
