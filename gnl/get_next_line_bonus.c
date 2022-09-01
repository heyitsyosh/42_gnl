/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myoshika <myoshika@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 16:26:45 by myoshika          #+#    #+#             */
/*   Updated: 2022/09/02 00:46:03 by myoshika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*read_till_nl_or_eof(int fd, char *buf, char *saved)
{
	ssize_t		read_status;
	char		*line;

	line = (char *)malloc(1);
	if (line)
		*line = '\0';
	read_status = 1;
	while (line && !ft_strchr(line, '\n') && read_status > 0)
	{
		read_status = read(fd, buf, BUFFER_SIZE);
		if (read_status < 0)
			ft_free(&line);
		else
		{
			buf[read_status] = '\0';
			line = ft_strjoin_with_free(line, buf, 1);
		}
	}
	if (line && saved && ft_strlen(saved) > 0)
		line = ft_strjoin_with_free(saved, line, 2);
	ft_free(&saved);
	return (line);
}

char	*get_next_line(int fd)
{
	char		*line;
	char		*buf;
	static char	*saved[256];

	if (BUFFER_SIZE <= 0 || fd < 0 || fd > 256)
		return (NULL);
	buf = (char *)malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	line = read_till_nl_or_eof(fd, buf, saved[fd]);
	if (line && ft_strchr(line, '\n'))
	{
		saved[fd] = ft_strjoin_with_free(ft_strchr(line, '\n') + 1, "", 0);
		line[ft_strchr(line, '\n') - line + 1] = '\0';
		line = ft_strjoin_with_free(line, "", 1);
	}
	else if (line && ft_strlen(line) < 1)
		ft_free(&line);
	ft_free(&buf);
	return (line);
}
