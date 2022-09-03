/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myoshika <myoshika@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 16:26:45 by myoshika          #+#    #+#             */
/*   Updated: 2022/09/04 08:31:18 by myoshika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*read_till_nl_or_eof(int fd, char *buf, char **saved)
{
	ssize_t		read_status;
	char		*line;

	line = (char *)malloc(1);
	if (line)
		*line = '\0';
	if (line && saved && *saved && (*saved)[0] != '\0')
		line = ft_strjoin_with_free(*saved, line, FREE_SECOND_PARAM);
	read_status = 1;
	while (line && !ft_strchr(line, '\n') && read_status > 0)
	{
		read_status = read(fd, buf, BUFFER_SIZE);
		if (read_status < 0)
			ft_safe_free(&line);
		else
		{
			buf[read_status] = '\0';
			line = ft_strjoin_with_free(line, buf, FREE_FIRST_PARAM);
		}
	}
	ft_safe_free(saved);
	return (line);
}

char	*get_next_line(int fd)
{
	char		*line;
	char		*buf;
	char		*ptr_to_nl;
	static char	*saved[INT_MAX + 1UL];

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	buf = (char *)malloc(BUFFER_SIZE + 1UL);
	if (!buf)
		return (NULL);
	line = read_till_nl_or_eof(fd, buf, &saved[fd]);
	ptr_to_nl = NULL;
	if (line)
		ptr_to_nl = ft_strchr(line, '\n');
	if (ptr_to_nl)
	{
		saved[fd] = ft_strjoin_with_free(ptr_to_nl + 1, "", FREE_NONE);
		line[ptr_to_nl - line + 1] = '\0';
	}
	else if (line && line[0] == '\0')
		ft_safe_free(&line);
	ft_safe_free(&buf);
	return (line);
}
