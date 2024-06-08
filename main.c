#include "get_next_line.h"

#include <stdio.h>
#include <fcntl.h>

int	main(int ac, char **av)
{
	(void)ac;
	int	f;
	char	*line;

	f = open(av[1], O_RDONLY);
	line = get_next_line(f);
	while (line)
	{
		printf("%s", line);
		free(line);
		line = get_next_line(f);
	}
	line = get_next_line(f);
	printf("%s", line);
	free(line);
	close(f);
	return (0);
}