/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myoshika <myoshika@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 16:49:10 by myoshika          #+#    #+#             */
/*   Updated: 2022/07/31 18:54:04 by myoshika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	read_fd(int fd, char *line)
{
	static char	buf[BUFFER_SIZE + 1];
	ssize_t		read_status;

	read_status = 1;
	while (strchr(line, '\0') && read_status > 0)
	{
		read_status = read(fd, buf, BUFFER_SIZE);
		
	}
	return (line);
}

char *get_next_line(int fd)
{
	char *line;

	if (BUFFER_SIZE <= 0 || fd < 0 || fd > RLIMIT_NOFILE)
		return (NULL);
	line = malloc(1);
	if (!line)
		return (NULL);
	line = read_fd(fd, ));
	return (line);
}
