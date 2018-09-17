#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

#include <string.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int    main(int ac, char **av)
{
 	char    *line;
    int   	fd;
    int		i;

 	i  = 1;
    if (ac == 2)
	{
		fd = open(av[1], O_RDONLY);

        line = NULL;
    	while (get_next_line(fd, &line))
		{
    		printf("%d. %s\n", i++, line);
    		free(line);
		}
	}
	return (0);
}
