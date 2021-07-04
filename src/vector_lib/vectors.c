/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectors.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zjamali <zjamali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 20:01:01 by zjamali           #+#    #+#             */
/*   Updated: 2021/07/04 13:46:57 by zjamali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vectors.h"
#include "../libft/libft.h"

int	ft_vector_resize(t_vector *vector, int new_capacity)
{
	int		status;
	void	**items;

	status = UNDEFINE;
	if (vector)
	{
		items = malloc(vector->item_size * new_capacity);
		ft_memcpy(items, vector->items, vector->item_size * vector->used);
		free(vector->items);
		vector->items = items;
		vector->size = new_capacity;
		status = SUCCESS;
	}
	return (status);
}

int	vector_push_back(t_vector *vector, void *item)
{
	int	status;

	status = UNDEFINE;
	if (vector)
	{
		if (vector->used == vector->size)
		{
			vector->vector_resize(vector, vector->size * 2);
			status = SUCCESS;
		}
		ft_memcpy(vector->items + vector->used * vector->item_size, item,
			vector->item_size);
		vector->used++;
	}
	return (status);
}

int	ft_vector_insert(t_vector *vector, int index, void *item)
{
	int		i;
	int		last_index;
	int		status;

	status = UNDEFINE;
	if (vector)
	{
		if (index >= 0 && index < vector->used)
		{
			vector->vector_add(vector, item);
			last_index = vector->used - 1;
			i = last_index;
			while (i > index)
			{
				ft_memcpy(vector->vector_get(vector, i),
					vector->vector_get(vector, i - 1), vector->item_size);
				i--;
			}
			ft_memcpy(vector->vector_get(vector, index), item,
				vector->item_size);
		}
		status = SUCCESS;
	}
	return (status);
}

int	ft_vector_set(t_vector *vector, int index, void *item)
{
	int	status;

	status = UNDEFINE;
	if (vector)
	{
		if (index >= 0 && index < vector->used)
		{
			ft_memcpy(vector->vector_get(vector, index), item,
				vector->item_size);
			status = SUCCESS;
		}
	}
	return (status);
}
