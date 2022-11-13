#include "get_next_line_bonus.h"
#include <stdio.h>
#include <fcntl.h>

#define ERR_FD "Error: open(\"file\", O_RDONLY)"

static int	f_swap_fd(int fd, int fd0, int fd1, int fd2)
{
	if (fd == fd0)
		fd = fd1;
	else if (fd == fd1)
		fd = fd2;
	else if (fd == fd2)
		fd = fd0;
	return (fd);
}

int	main(void)
{
	char			*line;
	register int	fd;
	register int	fd0;
	register int	fd1;
	register int	fd2;


	fd0 = open("./43_no_nl", O_RDONLY);
	fd1 = open("./get_next_line_utils.c", O_RDONLY);
	fd2 = open("./get_next_line.h", O_RDONLY);
	fd = fd0;
	if (3 > fd0 || 3 > fd1 || 3 > fd2)
		return(write(STDOUT_FILENO, ERR_FD, sizeof(ERR_FD) - sizeof(char)));
	while(NULL != (line = get_next_line(fd)))
	{
		printf("line:%s\n", line);
		free(line);
		line = NULL;
//		fd = f_swap_fd(fd, fd0, fd1, fd2);
	}
	printf("--DONE--\n");
	sleep(200);
	return (ZERO);
}
