/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igarg <igarg@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 13:37:02 by igarg             #+#    #+#             */
/*   Updated: 2021/10/19 10:22:19 by igarg            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

char	*process_read(int fd, char *str, char *buf)
{
	int	bytes;

	bytes = 1;
	while (!ft_strchr(str, '\n') && bytes != 0)
	{
		bytes = read(fd, buf, BUFFER_SIZE);
		if (bytes < 0)
		{
			free(buf);
			return (0);
		}
		buf[bytes] = '\0';
		if (!str)
			str = ft_substr(buf, 0, bytes);
		else
			str = ft_strjoin(str, buf);
	}
	free(buf);
	return (str);
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

char	*trim_start(char *str)
{
	int		start;
	char	*ret;

	start = 0;
	while (str[start] && str[start] != '\n')
		start++;
	start++;
	ret = ft_substr(str, start, ft_strlen(str));
	free(str);
	return (ret);
}

char	*get_next_line(int fd)
{
	char		*line;
	char		*buf;
	static char	*str;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (0);
	buf = malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (0);
	str = process_read(fd, str, buf);
	if (!str || str[0] == '\0')
	{
		free(str);
		str = 0;
		return (NULL);
	}
	line = trim_end(str);
	if (!line || line[0] == '\0')
	{
		free(line);
		return (0);
	}
	str = trim_start(str);
	return (line);
}
