#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdlib.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 64
# endif
# define ZERO 0
#define FALSE ZERO
# define TRUE 1

typedef struct s_list
{
	int				fd;
	char			*content;
	struct s_list	*next;
}	t_list;

typedef struct s_data
{
	struct s_list	list;
	int				fd;
	int				flag;
	int				r;
	char			*line;
	char			*aux;
}	t_data;

/**	get_next_line	**/
int		get_next_line(int fd);

/**	get_next_line_utils	**/
size_t	ft_strlen(const char *s);
void	*ft_calloc(size_t num_items, size_t size_item);
char	*ft_substr(char const *s, unsigned int start, size_t len, int flag)
char	*ft_strjoin_f1_f2(char *s1, char *s2);
int		gnl_isnl(char *str);

#endif
