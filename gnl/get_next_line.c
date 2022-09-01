/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myoshika <myoshika@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 16:49:10 by myoshika          #+#    #+#             */
/*   Updated: 2022/09/01 21:04:33 by myoshika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

static char	*read_till_nl_or_eof(int fd, char *buf, char **after_line)
{
	ssize_t		read_status;
	char		*line;
	//char		*tmp;
	line = (char *)malloc(1);
	if (line)
		*line = '\0';
	read_status = 1;
	while (line && !ft_strchr(line, '\n') && read_status > 0)
	{
		read_status = read(fd, buf, BUFFER_SIZE);
		if (read_status < 0)
		{
			ft_free(line);
			return (NULL);
		}
		buf[read_status] = '\0';
		// tmp = ft_strjoin_with_free(line, buf, 1);
		// line = tmp;
		line = ft_strjoin_with_free(line, buf, 1);
	}
	// printf("after_line: %d", NULL == *after_line);
	// fflush(stdout);
	if (read_status == 0)
		ft_free(*after_line);
	if (*after_line && **after_line)
	{
		// tmp = ft_strjoin_with_free(*after_line, line, 2);
		// line = tmp;
		line = ft_strjoin_with_free(*after_line, line, 2);
		ft_free(*after_line);
	}
	return (line);
}

char	*get_next_line(int fd)
{
	char		*line;
	char		*buf;
	static char	*after_line[257];
	//char		*tmp;
	if (BUFFER_SIZE <= 0 || fd < 0 || fd > 256)
		return (NULL);
	buf = (char *)malloc(BUFFER_SIZE + 1);
	if (!buf) //
		return (NULL);
	line = read_till_nl_or_eof(fd, buf, after_line);
	if (line && ft_strchr(line, '\n'))
	{
		after_line = ft_strjoin_with_free(ft_strchr(line, '\n'), "", 0);
		line[line - ft_strchr(line, '\n') + 1] = '\0';
		// tmp = ft_strjoin_with_free(line, "", 1);
		// line = tmp;
		line = ft_strjoin_with_free(line, "", 1);
	}
	else if (after_line && !*after_line)
	{
		ft_free(line);
		return (NULL);
	}
	ft_free(buf);
	return (line);
}
