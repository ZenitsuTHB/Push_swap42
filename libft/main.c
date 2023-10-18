# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <limits.h>
#include "libft.h"

int main(int ac, char **av)
{
	char *line;
	int fd1;
	line = "pokemon";
	fd1 = open(av[1], O_RDONLY);
	while (line)
	{
		line = get_next_line(fd1);
		if(line)
		{
			printf("%s",line);
			free(line);
		}
	}

}
