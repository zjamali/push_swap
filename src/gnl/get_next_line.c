/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zjamali <zjamali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 22:26:31 by zjamali           #+#    #+#             */
/*   Updated: 2021/07/08 18:53:21 by zjamali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
/*
static void	delete_node(t_list_line **head, int fd)
{
	t_list_line	*temp;
	t_list_line	*prev;

	temp = *head;
	if (temp != NULL && temp->fd == fd)
	{
		*head = temp->next;
		free(temp);
		temp = NULL;
		return ;
	}
	while (temp != NULL && temp->fd != fd)
	{
		prev = temp;
		temp = temp->next;
	}
	if (temp == NULL)
		return ;
	prev->next = temp->next;
	free(temp);
	temp = NULL;
}

static t_list_line	*lstnew(int fd)
{
	t_list_line	*lst;

	lst = (t_list_line *)malloc(sizeof(t_list_line));
	if (!lst)
		return (NULL);
	lst->fd = fd;
	lst->next = NULL;
	lst->str = NULL;
	return (lst);
}

static t_list_line	*check(t_list_line **lst, int fd)
{
	t_list_line	*ptr;

	if (*lst == NULL)
	{
		(*lst) = lstnew(fd);
		return (*lst);
	}
	ptr = *lst;
	if (ptr->fd == fd)
	{
		return (ptr);
	}
	while (ptr->next != NULL)
	{
		if (ptr->next->fd == fd)
		{
			return (ptr->next);
		}
		ptr = ptr->next;
	}
	ptr->next = lstnew(fd);
	return (ptr->next);
}

static int	get_line(t_list_line *lst, char **line, int n, t_list_line **head)
{
	char	*temp;
	int		i;

	i = 0;
	if (!lst->str)
		lst->str = ft_strdup("");
	temp = lst->str;
	while (lst->str[i] != '\n' && lst->str[i] != '\0')
		i++;
	*line = ft_substr(lst->str, 0, i);
	if (lst->str[i] == '\0' && n == 0)
	{
		delete_node(head, lst->fd);
		free(temp);
		temp = NULL;
		return (0);
	}
	else
		lst->str = ft_strdup(lst->str + i + 1);
	free(temp);
	if (!lst->str || !*line)
		return (-1);
	if (n || (n == 0 && lst->str != NULL))
		return (1);
	return (-1);
}

int	get_next_line(int fd, char **line)
{
	int					n;
	char				*buff;
	static t_list_line	*head;
	t_list_line			*lst;
	char				*temp;

	lst = check(&head, fd);
	buff = (char *)malloc(BUFFER_SIZE + 1);
	if (fd < 0 || fd > 4682 || buff == NULL \
			|| read(fd, buff, 0) || line == NULL || BUFFER_SIZE < 0)
		return (-1);
	n = read(fd, buff, BUFFER_SIZE);
	while (!ft_strchr(lst->str, '\n') && n > 0)
	{
		buff[n] = '\0';
		temp = lst->str;
		if (lst->str == NULL)
			lst->str = ft_strdup(buff);
		else
			lst->str = ft_strjoin(lst->str, buff);
		free(temp);
	}
	free(buff);
	return (get_line(lst, line, n, &head));
}
*/

int	is_n(char *str)
{
	while (*str)
	{
		if (*str == '\n')
			return (1);
		str++;
	}
	return (0);
}

char	*my_strcut(char *str, int n)
{
	int		len;
	int		i;
	char	*new;

	i = 0;
	len = ft_strlen(str);
	if (len > n)
		len = n;
	new = malloc(sizeof(char) * (len + 1));
	while (*str && len--)
		new[i++] = *str++;
	new[i] = '\0';
	return (new);
}

int	fill_line(char **content, char **line)
{
	int		end;
	char	*tmp;

	end = 0;
	while ((*content)[end] != '\n' && (*content)[end] != '\0')
		end++;
	if ((*content)[end] == '\n')
	{
		*line = my_strcut(*content, end);
		tmp = ft_strdup(*content + end + 1);
		free(*content);
		*content = tmp;
		return (1);
	}
	else if ((*content[end]) == '\0')
	{
		*line = ft_strdup(*content);
		free(*content);
	}
	if (*line[0] == '\0')
		free(*line);
	return (0);
}

int	get_next_line(char **line)
{
	int				r;
	static char		*content;
	char			*tmp;
	char			*buff;

	if (content == NULL)
		content = ft_strdup("");
	buff = malloc(sizeof(char) * 101);
	if (!is_n(content))
	{
		r = 1;
		while (r > 0)
		{
			buff[r] = '\0';
			tmp = ft_strjoin(content, buff);
			free(content);
			content = tmp;
			if (is_n(buff))
				break ;
			r = read(0, buff, 100);
		}
	}
	free(buff);
	return (fill_line(&content, line));
}
