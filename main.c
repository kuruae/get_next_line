#include "get_next_line.h"

int	main(int agrc, char **argv)
{
//	const char	*path = argv[1];
	int fd;

	fd = open(argv[1], O_RDONLY);
	while ((get_next_line(fd)) != NULL)
		printf("%s\n", (get_next_line(fd)));
	close(fd);
}
