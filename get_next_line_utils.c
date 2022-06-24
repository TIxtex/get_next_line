#include "get_next_line.h"

void	*ft_calloc(size_t num_items, size_t size_item)
{
	register void	*new;
	register size_t	bytes;
	register size_t	x;

	bytes = num_items * size_item;
	new = malloc(bytes);
	if (NULL != new)
	{
		x = ZERO;
		while (x < bytes)
		{
			new[x] = ZERO;
			x++;
		}
	}
	return (new);
}