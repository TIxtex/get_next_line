#include "get_next_line.h"

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
	while (data->fd < aux->fd && NULL != aux->next)
	{
		prev = aux;
		aux = aux->next;
	}
	if (-1 == aux->fd)
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

static void	gnl_core(t_data	*data)
{
	data->aux = NULL;
	data->flag = gnl_isnl(data->line);
	while (-1 == data->flag)
	{
		data->aux = (char *) ft_calloc(BUFFER_SIZE + 1, sizeof(char));
		data->r = read(data->fd, data->aux, BUFFER_SIZE);
		if (1 > data->r)
		{
			free(data->aux);
			if (-1 == data->r)
			{
				free(data->line);
				data->line = NULL;
			}
			else if ('\0' == *(data->line))
			{
				free(data->line);
				data->line = NULL;
			}
			return ;
		}
		data->line = ft_strjoin_f1_f2(data->line, data->aux);
		data->flag = gnl_isnl(data->line);
	}
	if ((int) ft_strlen(data->line) != data->flag + TRUE)
	{
		gnl_listadd(data, gnl_listnew(data->fd, gnl_substr(data->line,
			data->flag + 1, ft_strlen(data->line), FALSE)));
		data->line = gnl_substr(data->line, ZERO, data->flag, TRUE);
	}
}

char	*get_next_line(int fd)
{
	t_data			data;
	static t_list	list = {-1, NULL, NULL};

	if (ZERO > fd)
		return (NULL);
	data.fd = fd;
	data.list = (t_list *)&list;
	data.line = (char *) ft_calloc(TRUE, sizeof(char));
	gnl_check_fd(&data);
	gnl_core(&data);
	return (data.line);
}
