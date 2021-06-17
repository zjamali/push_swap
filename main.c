/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zjamali <zjamali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 20:21:59 by zjamali           #+#    #+#             */
/*   Updated: 2021/06/17 18:45:11 by zjamali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


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
		line = ft_strjoin(line, " ");
		free(tmp);
		i++;
	}
	data = ft_split(line, ' ');
	free(line);
	return (data);
}

void	ft_free_data(char **data)
{
	int	i;

	i = 0;
	while (data[i])
	{
		free(data[i]);
		i++;
	}
	free(data);
}

int	main(int ac, char **av)
{
	char	**data;
//	t_stack	stacks;
	//ft_init_stacks(&stacks);
	data = parse_arguments(av, ac);
	if (ft_check_data(data))
	{
		for (int i = 0; data[i] ; i++)
			printf("%d ",ft_atoi(data[i]));
		//ft_push_swap(data);
	}
	ft_free_data(data);
	return (0);
}
