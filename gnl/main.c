#include <stdio.h> //printf, perror
#include <fcntl.h> //open
#include <unistd.h> //close
#include <stdlib.h> //free
#include "get_next_line.h"

int	main(int argc, char **argv)
{
	if (argc < 2)
		return (0);

	int	fd = open(argv[1], O_RDONLY);
	if (fd == -1) {
		perror("Error opening file");
		return (1);
	}
	char *line = get_next_line(fd);
	while (line != NULL)
	{
		printf("%s", line);
		free(line);
		line = get_next_line(fd);
	}
	if (close(fd) == -1)
		perror("Error closing file");
	return (0);
}
