/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zjamali <zjamali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 11:31:05 by zjamali           #+#    #+#             */
/*   Updated: 2021/07/09 15:59:48 by zjamali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_check_argument(char *argument)
{
	int	len;
	int	i;
	int	number_found;

	i = 0;
	number_found = 0;
	len = ft_strlen(argument);
	while (i < len)
	{
		if (ft_strchr("0123456789", argument[i]))
			number_found = 1;
		i++;
	}
	if (number_found == 0)
		ft_display_error_and_exit();
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
		ft_check_argument(av[i]);
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
