#include "get_next_line.h"

int	main(int agrc, char **argv)
{
	const char	*path = argv[1];
	int fd;

	fd = open(path, O_RDONLY);
	printf("%s\n", (get_next_line(fd)));
}
