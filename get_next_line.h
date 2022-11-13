/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uliherre <uliherre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 14:26:03 by uliherre          #+#    #+#             */
/*   Updated: 2022/07/23 15:34:13 by uliherre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# include <unistd.h>
# include <stdlib.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif
# define ZERO 0
# define FALSE 0
# define TRUE 1

typedef struct s_gnl_substr
{
	char const	*sub_start;
	char const	*start;
	char		*new;
	size_t		size;
}	t_gnl_substr;

typedef struct s_list
{
	int				fd;
	char			*content;
	struct s_list	*next;
}	t_list;

typedef struct s_data
{
	struct s_list	*list;
	int				fd;
	int				flag;
	int				read_;
	char			*line;
	char			*read_line;
	void			*x;
}	t_data;

/**	get_next_line	**/
char	*get_next_line(int fd);

/**	get_next_line_utils	**/
size_t	ft_strlen(const char *s);
void	*gnl_scalloc(size_t num_items, size_t size_item);
char	*gnl_substr(char const *s, unsigned int start, size_t len, int flag);
char	*ft_strjoin_f1(char *s1, char *s2);
int		gnl_isnl(char *str);

#endif
