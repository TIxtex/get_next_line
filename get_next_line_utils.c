/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uliherre <uliherre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 14:25:59 by uliherre          #+#    #+#             */
/*   Updated: 2022/07/23 15:33:07 by uliherre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	register size_t	len;

	len = ZERO;
	while (ZERO != s[len])
		++len;
	return (len);
}

void	*gnl_scalloc(size_t num_items, size_t size_item)
{
	register char	*new;
	register size_t	bytes;

	bytes = num_items * size_item;
	new = (char *) malloc(bytes);
	if (NULL != new)
		new[bytes - TRUE] = ZERO;
	return ((void *) new);
}

char	*gnl_substr(char const *s, unsigned int start, size_t len, int flag)
{
	t_gnl_substr	data;

	if (NULL == s)
		return (NULL);
	if ('\0' == *s || start > ft_strlen(s))
		return ((char *) gnl_scalloc(TRUE, sizeof(char)));
	data.start = s;
	s += start;
	data.sub_start = s;
	data.size = TRUE;
	while ('\0' != *(s++) && ZERO != len--)
		data.size++;
	data.new = (char *) gnl_scalloc(data.size + sizeof(char), sizeof(char));
	if (NULL != data.new)
		while (ZERO < data.size--)
			data.new[data.size] = data.sub_start[data.size];
	if (TRUE == flag)
		free((void *) data.start);
	return (data.new);
}

char	*ft_strjoin_f1(char *s1, char *s2)
{
	register char	*nw_str;
	register char	*start;
	register char	*to_free;

	if (!s1 || !s2)
		return (NULL);
	nw_str = (char *) gnl_scalloc(
		ft_strlen(s1) + ft_strlen(s2) + sizeof(char),
		sizeof(char)
	);
	if (NULL == nw_str)
		return (NULL);
	start = nw_str;
	to_free = s1;
	while (ZERO != *s1)
		*(nw_str++) = *(s1++);
	while (ZERO != *s2)
		*(nw_str++) = *(s2++);
	free((void *) to_free);
	to_free = NULL;
	return (start);
}

int	gnl_isnl(char *str)
{
	register int	index;

	index = -1;
	while (ZERO != str[++index])
		if ('\n' == str[index] || '\r' == str[index])
			return (index);
	return (-1);
}
