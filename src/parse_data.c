/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zjamali <zjamali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 11:31:05 by zjamali           #+#    #+#             */
/*   Updated: 2021/07/08 12:35:05 by zjamali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
