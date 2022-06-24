#ifndef FT_GET_NEXT_LINE_H
# define FT_GET_NEXT_LINE_H
# include <unistd.h>
# include <stdlib.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 64
# endif

typedef struct s_lst
{
	int				*fd
	char			*content;
	struct s_lst	*next;
}	t_lst;


typedef struct s_data
{
	struct s_lst	lst;
	int				fd;
	char			*line;
}	t_data;

/**	get_next_line	**/
int	get_next_line(int fd);

/**	get_next_line_utils	**/
void	*ft_calloc(size_t num_items, size_t size_item);

#endif