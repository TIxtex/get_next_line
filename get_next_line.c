/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uliherre <uliherre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 14:25:44 by uliherre          #+#    #+#             */
/*   Updated: 2022/07/23 15:33:15 by uliherre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	gnl_list(t_data *data, int fd, char *content)
{
	t_list	*new;
	t_list	*aux;
	t_list	*prev;

	new = (t_list *) gnl_scalloc(TRUE, sizeof(t_list));
	if (NULL == new)
		return (FALSE);
	new->next = NULL;
	new->fd = fd;
	new->content = content;
	aux = data->list;
	while (data->fd > aux->fd && NULL != aux->next)
	{
		prev = aux;
		aux = aux->next;
	}
	if (NULL == aux->next || -1 == aux->fd)
		aux->next = new;
	else
	{
		new->next = aux;
		prev->next = new;
	}
	return (TRUE);
}

static void	gnl_check_fd(t_data *data)
{
	t_list	*aux;
	t_list	*prev;

	aux = data->list;
	while (NULL != aux->next && data->fd > aux->fd)
	{
		prev = aux;
		aux = aux->next;
	}
	if (data->fd == aux->fd)
	{
		data->line = aux->content;
		prev->next = aux->next;
		free((void *) aux);
		aux = NULL;
	}
	else
		data->line = (char *) gnl_scalloc(TRUE, sizeof(char));
}

static int	gnl_core(t_data	*d)
{
	d->read_line = (char *) gnl_scalloc(BUFFER_SIZE + TRUE, sizeof(char));
	gnl_check_fd(d);
	if (NULL == d->read_line || NULL == d->line)
		return (FALSE);
	d->flag = gnl_isnl(d->line);
	while (-1 == d->flag)
	{
		d->read_ = read(d->fd, d->read_line, BUFFER_SIZE);
		d->read_line[d->read_] = '\0';
		if (TRUE > d->read_)
		{
			d->flag = ft_strlen(d->line) - TRUE;
			free((void *) d->read_line);
			if ('\0' == *(d->line) || -1 == d->read_)
				return (FALSE);
			return (TRUE);
		}
		d->line = ft_strjoin_f1(d->line, d->read_line);
		d->flag = gnl_isnl(d->line);
	}
	return (free((void *) d->read_line), TRUE);
}

char	*get_next_line(int fd)
{
	static t_list	list = {-1, NULL, NULL};
	t_data			data;

	if (ZERO > fd || TRUE > BUFFER_SIZE)
		return (NULL);
	data.list = (t_list *)&list;
	data.fd = fd;
	if (FALSE == gnl_core(&data))
	{
		free((void *) data.line);
		data.line = NULL;
	}
	else if ((int) ft_strlen(data.line) != data.flag + sizeof(char))
	{
		data.x = gnl_substr(
			data.line,
			data.flag + sizeof(char),
			ft_strlen(data.line),
			FALSE
			);
		if (NULL == data.x || !gnl_list(&data, data.fd, (char *) data.x))
			return (free((void *) data.line) , NULL);
		data.line = gnl_substr(data.line, ZERO, data.flag, TRUE);
	}
	return (data.line);
}
