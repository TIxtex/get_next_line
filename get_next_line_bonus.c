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

#include "get_next_line_bonus.h"

static t_list	*gnl_listnew(int fd, char *content)
{
	t_list	*new;

	new = (t_list *) ft_calloc(1, sizeof(t_list));
	if (NULL != new)
	{
		new->fd = fd;
		new->content = content;
		new->next = NULL;
	}
	return (new);
}

static void	gnl_listadd(t_data *data, t_list *add)
{
	t_list	*aux;
	t_list	*prev;

	aux = data->list;
	while (data->fd > aux->fd && NULL != aux->next)
	{
		prev = aux;
		aux = aux->next;
	}
	if (-1 == aux->fd || NULL == aux->next)
		aux->next = add;
	else
	{
		add->next = aux;
		prev->next = add;
	}
}

static void	gnl_check_fd(t_data *data)
{
	t_list	*aux;
	t_list	*prev;

	aux = data->list;
	while (data->fd > aux->fd && NULL != aux->next)
	{
		prev = aux;
		aux = aux->next;
	}
	if (aux->fd == data->fd)
	{
		data->line = ft_strjoin_f1_f2(data->line, aux->content);
		prev->next = aux->next;
		free(aux);
		aux = NULL;
	}
}

static int	gnl_core(t_data	*d)
{
	while (-1 == d->flag)
	{
		d->read_line = (char *) ft_calloc(BUFFER_SIZE + 1, sizeof(char));
		if (NULL == d->read_line)
			return (TRUE);
		d->r = read(d->fd, d->read_line, BUFFER_SIZE);
		if (1 > d->r)
		{
			free(d->read_line);
			if ('\0' == *(d->line) || -1 == d->r)
				return (TRUE);
			return (FALSE);
		}
		d->line = ft_strjoin_f1_f2(d->line, d->read_line);
		d->flag = gnl_isnl(d->line);
	}
	if ((int) ft_strlen(d->line) != d->flag + 1)
	{
		gnl_listadd(d, gnl_listnew(d->fd,
				gnl_substr(d->line, d->flag + 1, ft_strlen(d->line), 0)));
		d->line = gnl_substr(d->line, ZERO, d->flag, TRUE);
	}
	return (FALSE);
}

char	*get_next_line(int fd)
{
	t_data			data;
	static t_list	list = {-1, NULL, NULL};

	if (ZERO > fd || TRUE > BUFFER_SIZE)
		return (NULL);
	data.list = (t_list *)&list;
	data.fd = fd;
	data.line = (char *) ft_calloc(TRUE, sizeof(char));
	data.read_line = NULL;
	gnl_check_fd(&data);
	data.flag = gnl_isnl(data.line);
	if (TRUE == gnl_core(&data))
	{
		free(data.line);
		data.line = NULL;
	}
	return (data.line);
}
