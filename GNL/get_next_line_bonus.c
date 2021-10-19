/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igarg <igarg@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 13:37:02 by igarg             #+#    #+#             */
/*   Updated: 2021/10/18 15:01:32 by igarg            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

char	*process_read(int fd, char **str, char *buf)
{
	int	bytes;

	bytes = 1;
	while (!ft_strchr(str[fd], '\n') && bytes != 0)
	{
		bytes = read(fd, buf, BUFFER_SIZE);
		if (bytes < 0)
		{
			free(buf);
			return (0);
		}
		buf[bytes] = '\0';
		if (!str[fd])
			str[fd] = ft_substr(buf, 0, bytes);
		else
			str[fd] = ft_strjoin(str[fd], buf);
	}
	free(buf);
	return (str[fd]);
}

char	*trim_end(char *str)
{
	char	*line;
	int		len;

	len = 0;
	while (str[len] && str[len] != '\n')
		len++;
	if (str[len] == '\n')
		len++;
	line = ft_substr(str, 0, len);
	return (line);
}

char	*trim_start(char **str, int fd)
{
	int		start;
	char	*ret;

	start = 0;
	while (str[fd][start] && str[fd][start] != '\n')
		start++;
	if (!str[fd][start])
	{
		free(str[fd]);
		return (NULL);
	}
	start++;
	ret = ft_substr(str[fd], start, ft_strlen(str[fd]));
	free(str[fd]);
	str[fd] = 0;
	return (ret);
}

char	*get_next_line(int fd)
{
	char		*line;
	char		*buf;
	static char	*str[4096];

	if (fd < 0 || BUFFER_SIZE < 1)
		return (0);
	buf = malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (0);
	str[fd] = process_read(fd, str, buf);
	if (!str[fd] || str[fd][0] == '\0')
	{
		free(str[fd]);
		str[fd] = 0;
		return (0);
	}
	line = trim_end(str[fd]);
	if (line[0] == '\0')
	{
		free(line);
		line = 0;
		return (0);
	}
	str[fd] = trim_start(str, fd);
	return (line);
}
