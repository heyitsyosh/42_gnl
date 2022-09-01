#include <unistd.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <limits.h>
#include "get_next_line.h"

// #define BUFFER_SIZE 4

int main()
{
	char	buf[4 + 1];
	int fd = open("test.txt", O_RDONLY);
	printf("%s", get_next_line(fd));
	//printf("%d", NULL == get_next_line(fd));
	// ssize_t read_status = read(fd, buf, BUFFER_SIZE);
	// printf("[%d][%s]", read_status, buf);
	// // read_status = read(fd, buf, BUFFER_SIZE);
	// // printf("[%d][%s]", read_status, buf);
	// printf("%lu", OPEN_MAX);
}